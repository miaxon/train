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

            int LocalObject::Call(data::Tuple& header, data::Tuple& params, data::RawData* raw_data) {
                zmqpp::message zmsg;
                zmsg.add_raw(header.data(), header.size());                
                zmsg.add_raw(params.data(), params.size());
                if(nullptr != raw_data)
                    zmsg.add_raw(raw_data->data(), raw_data->size());
                m_client.Send(zmsg);
            }
        }
    }
}

