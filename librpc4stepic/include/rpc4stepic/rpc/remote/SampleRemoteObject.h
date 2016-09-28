/* 
 * File:   FileSystem.h
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#ifndef SAMPLE_H
#define	SAMPLE_H
#include <cstdlib>
#include <string>
#include "RemoteObject.h"

namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            class SampleRemoteObject : public RemoteObject {
            public:
                SampleRemoteObject();
                SampleRemoteObject(const SampleRemoteObject& orig);
                virtual ~SampleRemoteObject();
                
            private:

            };
        }
    }
}
#endif	/* FILESYSTEM_H */
