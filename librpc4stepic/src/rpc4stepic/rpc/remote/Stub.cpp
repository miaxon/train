/* 
 * File:   RPCObject.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#include "rpc/remote/Stub.h"
#include "data/Header.h"
#include "rpc/remote/SampleStub.h"
namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            Stub::Stub(zmqpp::message* request, zmqpp::message* responce) : m_request(msg), m_responce(responce) {
            }

            Stub::~Stub() {
            }

            const void* Stub::TupleData() {
                return m_request->raw_data(1);
            }

            size_t Stub::TupleSize() {
                return m_request->size(1);
            }

            const void* Stub::RawData() {

                return m_request->raw_data(2);
            }

            size_t Stub::RawDataSize() {
                return m_request->size(2);
            }

            data::Header* Stub::Header() {
                return new data::Header(m_request->raw_data(0), m_request->size(0));
            }

            int Stub::Call() {
                data::Header* h = Header();
                std::string& caller = h->Caller();
                // TO DO replace header caller to real method pointer
                remote::SampleStub sample_stub;
            }

        }
    }
}

