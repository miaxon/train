/* 
 * File:   ZMQServer.h
 * Author: alex
 *
 * Created on 22 Сентябрь 2016 г., 21:19
 */

#ifndef ZMQSERVER_H
#define	ZMQSERVER_H

#include <string>
#include <zmqpp/zmqpp.hpp>
#include "serialize/Request.h"
#include "ZMQWorker.h"
#include "Error.h"
#include "Defines.h"
namespace rpc4stepic {
    namespace net {
        using namespace std;
        class ZMQServer {
        public:
            ZMQServer();
            virtual ~ZMQServer();
            
            Error StartLocal();
            
        private:
            zmqpp::context m_ctx;
            zmqpp::socket m_frontend;
            zmqpp::socket m_backend;
            int m_num_workers;
        };
    }
}
#endif	/* ZMQSERVER_H */

