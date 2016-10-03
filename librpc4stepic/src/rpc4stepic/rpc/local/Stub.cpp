/* 
 * File:   RPCObject.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#include "rpc/local/Stub.h"
#include "data/Header.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            Stub::Stub(zmqpp::endpoint_t& endpoint) : m_client(endpoint) {
            }

            Stub::~Stub() {
            }            
            
            const void* Stub::TupleData(){
                return m_msg->raw_data(1);
            }
            size_t Stub::TupleSize(){
                return m_msg->size(1);
            }
            const void* Stub::RawData(){
                
                return m_msg->raw_data(2);
            }
            size_t Stub::RawDataSize(){
                return m_msg->size(2);
            }
            bool Stub::Call(std::string caller, data::Tuple& params, data::RawData* raw_data) {
                data::Header header(caller);
                zmqpp::message req, rsp;
                req.add_raw(header.data(), header.size());                
                req.add_raw(params.data(), params.size());
                if(nullptr != raw_data)
                    req.add_raw(raw_data->data(), raw_data->size());
                if( m_client.Send(req, rsp))
                {
                    m_msg = &rsp;
                    return true;
                }
                return false;
                
            }
            
        }
    }
}

