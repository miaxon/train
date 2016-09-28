/* 
 * File:   RPCObject.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#ifndef RPCOBJECT_H
#define	RPCOBJECT_H
#include "net/ZMQClient.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            class LocalObject {
            public:
                LocalObject();
                LocalObject(const LocalObject& orig);
                virtual ~LocalObject();
                virtual int Initialize(zmqpp::endpoint_t& endpoint, std::string& remote_class);
            protected:
                net::ZMQClient m_client;
                std::string m_remote_class;
            private:
                

            };
        }
    }
}
#endif	/* RPCOBJECT_H */

