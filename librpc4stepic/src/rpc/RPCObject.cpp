/* 
 * File:   RPCObject.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#include "RPCObject.h"
namespace rpc4stepic {

    RPCObject::RPCObject() {
    }

    RPCObject::RPCObject(const RPCObject& orig) {
    }

    RPCObject::~RPCObject() {
    }
    int RPCObject::call(const serialize::Request& req, serialize::Responce& rsp){
        return 0;
    }
}

