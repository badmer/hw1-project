//
// Created by MSI on 2018/8/30.
//

#ifndef PROJECT_JACK_SERVICE_H
#define PROJECT_JACK_SERVICE_H



#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {
    class JACK_Service : public BBinder {
    private:
        //mutable Mutex m_Lock;
        //int32_t m_NextConnId;

    public:
        static int Instance();

        JACK_Service();

        virtual ~JACK_Service();

        virtual status_t onTransact(uint32_t, const Parcel &, Parcel *, uint32_t);
    };
}

#endif //PROJECT_JACK_SERVICE_H
