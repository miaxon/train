/* 
 * File:   RPCObject.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#ifndef RPCOBJECT_H
#define	RPCOBJECT_H
#include "net/ZMQClient.h"
#include "data/Tuple.h"
#include "data/RawData.h"
#include "data/Header.h"
#define REMOTE_CALL(x) Call(std::string(__PRETTY_FUNCTION__), x)

namespace rpc4stepic {
    namespace rpc {
        namespace local {

            class Stub {
            public:
                Stub(zmqpp::endpoint_t& endpoint);
                virtual ~Stub();
                
            protected:
                bool Call(std::string caller, data::Tuple& params, data::RawData* raw_data = nullptr);
                
                const void* TupleData();
                const void* RawData();
                size_t TupleSize();
                size_t RawDataSize();
                              
                
            private:
                net::ZMQClient m_client;
                zmqpp::message* m_msg; 

            };
        }
    }
}
#endif	/* RPCOBJECT_H */

