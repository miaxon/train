/* 
 * File:   RPCObject.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#ifndef RPCOBJECT_H
#define	RPCOBJECT_H
#include "ZMQClient.h"
#include "Request.h"
#include "Responce.h"
namespace rpc4stepic {

    class RPCObject {
    public:
        RPCObject();
        RPCObject(const RPCObject& orig);
        virtual ~RPCObject();
    protected:
        int call(const Request& req, Responce& rsp);
    private:
        net::ZMQClient client;

    };
}
#endif	/* RPCOBJECT_H */

