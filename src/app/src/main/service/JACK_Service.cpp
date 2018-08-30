//
// Created by MSI on 2018/8/30.
//

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "JACK_Service.h"
#include "../log.h"

namespace android
{
    //static struct sigaction oldact;
    static pthread_key_t sigbuskey;

    int JACK_Service::Instance()
    {
        DebugPrint("JACK_Service Instantiate\n");
        int ret = defaultServiceManager()->addService(
                String16("jack.svc"), new JACK_Service());
        DebugPrint(" JACK_Service ret = %d\n", ret);
        return ret;
    }

    JACK_Service::JACK_Service()
    {
        DebugPrint(" JACK_Service create\n");
        //m_NextConnId = 1;
        pthread_key_create(&sigbuskey,NULL);
    }

    JACK_Service::~JACK_Service()
    {
        pthread_key_delete(sigbuskey);
        DebugPrint(" JACK_Service destory\n");
    }

    status_t JACK_Service::onTransact(uint32_t code,
                                      const Parcel& data,
                                      Parcel* reply,
                                      uint32_t flags)
    {
        switch(code)
        {
            case 0:
            {
                pid_t pid = data.readInt32();
                int num = data.readInt32();
                num += 1000;
                reply->writeInt32(num);
                return NO_ERROR;
            } break;
            case 1:
            {
                pid_t pid = data.readInt32();
                String8 str = data.readString8();
                DebugPrint(" case 1 = %s \n",str.string());
                String8 add_str = String8("jack_service get ")+str;
                //str = add_str + str;
                reply->writeString8(add_str);
                return NO_ERROR;
            } break;
            default:
                return BBinder::onTransact(code, data, reply, flags);
        }
    }

