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
#include "zmqpp/context.hpp"
#include "zmqpp/message.hpp"
#include "zmqpp/proxy.hpp" 
#include "serialize/Request.h"
#include "ZMQWorker.h"
#include "Error.h"
#include "Defines.h"
#include "easylogging++.h"
namespace rpc4stepic {
    namespace net {
        using namespace std;

        class ZMQServer {
        public:
            ZMQServer(zmqpp::endpoint_t& endpoint, int nworkers = 5);
            virtual ~ZMQServer();



        private:
            void run();
            int m_nworkers;
            zmqpp::context m_ctx;
            zmqpp::socket m_frontend;
            zmqpp::socket m_backend;
            std::string m_endpoint;
            
        };
    }
}
#endif	/* ZMQSERVER_H */

