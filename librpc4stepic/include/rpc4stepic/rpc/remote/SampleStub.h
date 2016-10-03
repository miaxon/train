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
#include "Stub.h"

namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            class SampleStub : public Stub {
            public:
                SampleStub(zmqpp::message* request, zmqpp::message* responce);
                virtual ~SampleStub();
                int Call();
            private:

            };
        }
    }
}
#endif	/* FILESYSTEM_H */
