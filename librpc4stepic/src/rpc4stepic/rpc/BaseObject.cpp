/* 
 * File:   RPCObject.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 9:30
 */

#include "rpc/BaseObject.h"
namespace rpc4stepic {
    namespace rpc {

        BaseObject::BaseObject() {
        }

        BaseObject::BaseObject(const BaseObject& orig) {
        }

        BaseObject::~BaseObject() {
        }

        int BaseObject::call(const serialize::Request& req, serialize::Responce& rsp) {
            return 0;
        }
    }
}

