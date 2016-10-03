/* 
 * File:   RPCObject.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#ifndef RPCOBJECT_H
#define	RPCOBJECT_H
#include "net/ZMQClient.h"
#include "net/ZMQClient.h"
#include "data/Header.h"
#include "data/RawData.h"
#include "data/Tuple.h"
namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            class Stub {
            public:
                Stub(zmqpp::message* request, zmqpp::message* responce);
                virtual ~Stub();
            protected:
                data::Header* Header();
                const void* TupleData();
                const void* RawData();
                size_t TupleSize();
                size_t RawDataSize();
                virtual int Call();
                
            private:
               zmqpp::message* m_request;
               zmqpp::message* m_responce;

            };
        }
    }
}
#endif	/* RPCOBJECT_H */

