#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <binder.h>

#include "test_server.h"
#include "com_example_myapplication_CserviceInterface.h"


typedef unsigned int uint32_t;

uint32_t svcmgr_lookup(struct binder_state *bs, uint32_t target, const char *name)
{
	uint32_t handle;
	unsigned iodata[512 / 4];
	struct binder_io msg, reply;

	bio_init(&msg, iodata, sizeof(iodata), 4);
	bio_put_uint32(&msg, 0);  // strict mode header
	bio_put_string16_x(&msg, SVC_MGR_NAME);
	bio_put_string16_x(&msg, name);

	if (binder_call(bs, &msg, &reply, target, SVC_MGR_CHECK_SERVICE))
		return 0;

	handle = bio_get_ref(&reply);

	if (handle)
		binder_acquire(bs, handle);

	binder_done(bs, &msg, &reply);

	return handle;
}


struct binder_state *g_bs;
uint32_t g_hello_handle;
uint32_t g_goodbye_handle;

void sayhello(void)
{
	unsigned iodata[512 / 4];
	struct binder_io msg, reply;

	bio_init(&msg, iodata, sizeof(iodata), 4);
	bio_put_uint32(&msg, 0);  // strict mode header
	bio_put_string16_x(&msg, "IHelloService");

	if (binder_call(g_bs, &msg, &reply, g_hello_handle, HELLO_SVR_CMD_SAYHELLO))
		return;

	binder_done(g_bs, &msg, &reply);

}

JNIEXPORT void JNICALL Java_com_example_myapplication_CserviceInterface_cservice(JNIEnv *, jclass) {
	struct binder_state *bs;
	uint32_t svcmgr = BINDER_SERVICE_MANAGER;
	uint32_t handle;

	bs = binder_open(128 * 1024);
	if (!bs) {
		fprintf(stderr, "failed to open binder driver\n");
		return -1;
	}
	g_bs = bs;


	/* get service */
	handle = svcmgr_lookup(bs, svcmgr, "hello");
	g_hello_handle = handle;

	/* send data to server */
	sayhello();

	binder_release(bs, handle);
}