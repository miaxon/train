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

            LocalObject::LocalObject() {
            }

            LocalObject::LocalObject(const LocalObject& orig) {
            }

            LocalObject::~LocalObject() {
            }

            int LocalObject::Initialize(zmqpp::endpoint_t& endpoint, std::string& use_class) {
                m_client.Connect(endpoint);
                m_remote_class = use_class;
            }
        }
    }
}

