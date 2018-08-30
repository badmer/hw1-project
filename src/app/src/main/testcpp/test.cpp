//
// Created by MSI on 2018/8/30.
//

#include <stdio.h>
#include "../svcclient/JACK_Client.h"
#include "../log.h"
#include <utils/String8.h>

using namespace android;

int main(int argc, char** argv)
{
    JACK_Client client;
    DebugPrint(" start test");
    int ret = client.setN(2017);
    DebugPrint("setN return: %d\n", ret);
    String8 send = String8("hello I'm string");
    String8 str = client.setString8(send);
    DebugPrint("setString8 return: %s\n",str.string());
    //ALOGE("chyj setString8 return %s",str.string());
    return 0;
}
