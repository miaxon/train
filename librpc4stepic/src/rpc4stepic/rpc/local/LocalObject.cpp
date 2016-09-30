/* 
 * File:   RPCObject.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#include "rpc/local/LocalObject.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            LocalObject::LocalObject(zmqpp::endpoint_t& endpoint) : m_client(endpoint) {
            }

            LocalObject::~LocalObject() {
            }

            int LocalObject::Call(data::params& header, data::params& params, void* raw_data) {
                zmqpp::message zmsg;
                zmsg.add_raw(header.data(), header.size());                
                    
                m_client.Send(zmsg);
            }
        }
    }
}

