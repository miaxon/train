/* 
 * File:   Packer.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 12:39
 */

#include "Packer.h"
namespace serialize {

    Packer::Packer() {
    }

    Packer::Packer(const Packer& orig) {
    }

    Packer::~Packer() {
    }
    void* Packer::Pack(Request& req){
        return nullptr;
    }
    Responce Packer::Unpack(void* data){
        Responce rsp;
        return rsp;
    }
}

