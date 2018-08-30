//
// Created by MSI on 2018/8/30.
//

#ifndef ANDROID_JACK_CLIENT_H
#define ANDROID_JACK_CLIENT_H
#include <binder/Parcel.h>

namespace android
{
    class JACK_Client
    {
    public:
        int setN(int n);
        String8 setString8(String8 str);
    private:
        static void getJACK_Service();
    };
}



#endif //PROJECT_JACK_CLIENT_H
