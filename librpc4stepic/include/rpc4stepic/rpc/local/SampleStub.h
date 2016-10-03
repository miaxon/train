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
        namespace local {

            class SampleStub : public Stub {
            public:
                SampleStub(zmqpp::endpoint_t& endpoint);                
                virtual ~SampleStub();
                std::string SampleMethod(int i, bool b, std::string s);
            private:

            };
        }
    }
}
#endif	/* FILESYSTEM_H */
