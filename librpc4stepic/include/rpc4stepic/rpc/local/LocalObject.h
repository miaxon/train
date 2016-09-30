/* 
 * File:   RPCObject.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#ifndef RPCOBJECT_H
#define	RPCOBJECT_H
#include "net/ZMQClient.h"
#include "data/Params.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            class LocalObject {
            public:
                LocalObject(zmqpp::endpoint_t& endpoint);
                virtual ~LocalObject();
                
            protected:
                int Call(data::params& header, data::params& params, void* raw_data = nullptr);
                
            private:
                net::ZMQClient m_client;

            };
        }
    }
}
#endif	/* RPCOBJECT_H */

