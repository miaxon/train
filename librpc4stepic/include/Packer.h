/* 
 * File:   Packer.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 12:39
 */

#ifndef PACKER_H
#define	PACKER_H
#include "Request.h"
#include "Responce.h"
namespace serialize {

    class Packer {
    public:
        Packer();
        Packer(const Packer& orig);
        virtual ~Packer();
        void* Pack(Request& req);
        Responce Unpack(void* data);
    private:

    };
}

#endif	/* PACKER_H */

