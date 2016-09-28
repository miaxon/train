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
namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            class RemoteObject {
            public:
                RemoteObject();
                RemoteObject(const RemoteObject& orig);
                virtual ~RemoteObject();
            protected:
                
            private:
                //net::ZMQClient client("");

            };
        }
    }
}
#endif	/* RPCOBJECT_H */

