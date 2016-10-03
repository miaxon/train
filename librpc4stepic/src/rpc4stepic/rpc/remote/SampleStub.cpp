/* 
 * File:   FileSystem.cpp
 * Author: alex
 * 
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#include "rpc/remote/SampleStub.h"
namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            SampleStub::SampleStub(zmqpp::message* request, zmqpp::message* responce):Stub(request, responce) {
            }


            SampleStub::~SampleStub() {
            }
            int SampleStub::Call()
            {
                data::Header* h = Header();
                std::string& caller = h->Caller();
                // TO DO replace header caller to real method pointer
                remote::SampleStub;
                
            }
        }
    }
}