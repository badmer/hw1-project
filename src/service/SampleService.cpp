#include <binder/IServiceManager.h>

#include <binder/IBinder.h>

#include <binder/Parcel.h>

#include <binder/ProcessState.h>

#include <binder/IPCThreadState.h>

using namespace android;

#ifdef LOG_TAG

#undef LOG_TAG

#endif

#define LOG_TAG "sampleService"

#define SAMPLE_SERIVCE_DES "sample.hello"

#define FUNC_CALLFUNCTION 1


//SampleService类继承于BBinder
class SampleService: public BBinder {

public:

     SampleService() {

          mydescriptor = String16(SAMPLE_SERIVCE_DES);

     }

     

     virtual ~SampleService() {

     }




     virtual const String16& getInterfaceDescriptor() const {

           return mydescriptor;

     }

     

protected:

     

     void callFunction() {

          LOGE( "Service callFunction-----------");

     }

     

     virtual status_t onTransact(uint32_t code, const Parcel& data,

              Parcel* reply, uint32_t flags = 0) {

          LOGD( "Service onTransact, code = %d" , code);

           switch (code) {

			//如果code是1，执行callFunction函数，并跳出，return 0
           case FUNC_CALLFUNCTION:

              callFunction();

               break;

			//如果code不是1，则返回这个函数继续执行，保证不会退出
           default:

               return BBinder::onTransact(code, data, reply, flags);

          }

           return 0;

     }

private:

     String16 mydescriptor;

};




int main() {

	 //ServiceManager
     sp < IServiceManager > sm = defaultServiceManager();	

	 
	 //新new一个SampleService类
     SampleService* samServ = new SampleService();

	 //通过sm将该类添加到服务列表
     status_t ret = sm->addService(String16(SAMPLE_SERIVCE_DES), samServ);

     LOGD("Service main addservice ");

     ProcessState::self()->startThreadPool();

     IPCThreadState::self()->joinThreadPool( true);

     return 0;

}
