#include "binder\IServiceManager.h"
#include "binder\IBinder.h"
#include "binder\Parcel.h"
#include "binder\ProcessState.h"
#include "binder\IPCThreadState.h"
#include "binder\Binder.h"
#include "utils\RefBase.h"

using namespace android;

class Service : public BBinder
{
public:
	Service()
	{

	}
	~Service()
	{

	}

private:

protected:
	//override
	virtual status_t Service::onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags = 0)
	{
		//do nothing.....
	}
};

int main(){
	sp<IServiceManager> sm = defaultServiceManager();
	status_t ret;
	Service *srv = new Service();
	ret = sm->addService(String16("do nothing"), srv);
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();
	return 0;
	
}