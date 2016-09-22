/* 
 * File:   RPCObject.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#ifndef RPCOBJECT_H
#define	RPCOBJECT_H
#include "net/ZMQClient.h"
#include "serialize/Request.h"
#include "serialize/Responce.h"
namespace rpc4stepic {
    namespace rpc {

        class BaseObject {
        public:
            BaseObject();
            BaseObject(const BaseObject& orig);
            virtual ~BaseObject();
        protected:
            int call(const serialize::Request& req, serialize::Responce& rsp);
        private:
            net::ZMQClient client;

        };
    }
}
#endif	/* RPCOBJECT_H */

