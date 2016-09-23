/* 
 * File:   ZMQClient.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:49
 */

#ifndef ZMQCLIENT_H
#define	ZMQCLIENT_H
#include <cstdlib>
#include <string>
#include <zmqpp/zmqpp.hpp>
#include "serialize/Request.h"
#include "easylogging++.h"
#include "Defines.h"
namespace rpc4stepic {
    namespace net {

        class ZMQClient {
        public:
            ZMQClient();
            ZMQClient(const zmqpp::endpoint_t& endpoint);
            virtual ~ZMQClient();
            void Send(const std::string& msg);
            int Send(const rpc4stepic::serialize::Request&);
            int SendAsync(const rpc4stepic::serialize::Request&);
        private:
            zmqpp::context m_ctx;
            zmqpp::socket m_socket;
            zmqpp::endpoint_t m_endpoint;
        };
    }
}
#endif	/* ZMQCLIENT_H */

