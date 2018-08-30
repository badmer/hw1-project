#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <binder.h>

#include "test_server.h"

typedef unsigned int            uint32_t;

typedef unsigned short int      uint16_t;

int svcmgr_publish(struct binder_state *bs, uint32_t target, const char *name, void *ptr)
{
	int status;
	unsigned iodata[512 / 4];
	struct binder_io msg, reply;

	bio_init(&msg, iodata, sizeof(iodata), 4);
	bio_put_uint32(&msg, 0);  // strict mode header
	bio_put_string16_x(&msg, SVC_MGR_NAME);
	bio_put_string16_x(&msg, name);
	bio_put_obj(&msg, ptr);

	if (binder_call(bs, &msg, &reply, target, SVC_MGR_ADD_SERVICE))
		return -1;

	status = bio_get_uint32(&reply);

	binder_done(bs, &msg, &reply);

	return status;
}

void sayhello(void)
{
	static int cnt = 0;
	fprintf(stderr, "say hello : %d\n", ++cnt);
}

int hello_service_handler(struct binder_state *bs,
	struct binder_transaction_data *txn,
	struct binder_io *msg,
	struct binder_io *reply)
{
	uint32_t strict_policy;

	strict_policy = bio_get_uint32(msg);

	sayhello();
	bio_put_uint32(reply, 0);
	return 0;
}

int test_server_handler(struct binder_state *bs,
	struct binder_transaction_data *txn,
	struct binder_io *msg,
	struct binder_io *reply)
{
	int(*handler)(struct binder_state *bs,
		struct binder_transaction_data *txn,
		struct binder_io *msg,
		struct binder_io *reply);

	handler = (int(*)(struct binder_state *bs,
		struct binder_transaction_data *txn,
		struct binder_io *msg,
		struct binder_io *reply))txn->target.ptr;

	return handler(bs, txn, msg, reply);
}

int main(int argc, char **argv)
{
	int fd;
	struct binder_state *bs;
	uint32_t svcmgr = BINDER_SERVICE_MANAGER;
	uint32_t handle;
	int ret;

	bs = binder_open(128 * 1024);
	if (!bs) {
		fprintf(stderr, "failed to open binder driver\n");
		return -1;
	}

	/* add service */
	ret = svcmgr_publish(bs, svcmgr, "hello", hello_service_handler);
	if (ret) {
		fprintf(stderr, "failed to publish hello service\n");
		return -1;
	}

	binder_set_maxthreads(bs, 10);

	binder_loop(bs, test_server_handler);

	return 0;
}