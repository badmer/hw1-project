//
// Created by MSI on 2018/8/30.
//

#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include "JACK_Client.h"
#include "../log.h"
#include<android/log.h>
namespace android
{
    sp<IBinder> binder;

    int JACK_Client::setN(int n)
    {
        getJACK_Service();
        Parcel data, reply;
        data.writeInt32(getpid());
        data.writeInt32(n);

        DebugPrint(" client - binder->transact()\n");
        binder->transact(0, data, &reply);
        int r = reply.readInt32();
        return r;
    }
    String8 JACK_Client::setString8(String8 str)
    {
        getJACK_Service();
        Parcel data, reply;//获取或创建Parcel对象
        data.writeInt32(getpid());//写入Parcel数据
        data.writeString8(str);
        //ALOGE("chyj send %s",str.string());
        DebugPrint(" client - binder->transact() send %s \n",str.string());
        binder->transact(1, data, &reply);//通过Binder传递数据 1是函数顺序号，必须对应
        String8 r = reply.readString8();//reply接收数据
        DebugPrint(" setString8 reply %s \n",r.string());
        //ALOGE("chyj reply %s",r.string());
        return r;
    }
    void JACK_Client::getJACK_Service()
    {
        sp<IServiceManager> sm = defaultServiceManager();
        binder = sm->getService(String16("jack.svc"));
        DebugPrint(" client - etService: %p\n", sm.get());
        if(binder == 0)
        {
            DebugPrint(" JACK_Service not published, waiting...");
            return;
        }
    }

}

