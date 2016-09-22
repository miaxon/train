/* 
 * File:   ZMQServer.h
 * Author: alex
 *
 * Created on 22 Сентябрь 2016 г., 21:19
 */

#ifndef ZMQSERVER_H
#define	ZMQSERVER_H

#include <zmqpp/zmqpp.hpp>
#include "serialize/Request.h"
namespace rpc4stepic {
    namespace net {

        class ZMQServer {
        public:
            ZMQServer();
            ZMQServer(const ZMQServer& orig);
            virtual ~ZMQServer();
        private:
        };
    }
}
#endif	/* ZMQSERVER_H */

