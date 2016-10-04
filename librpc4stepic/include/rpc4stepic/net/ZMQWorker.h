/* 
 * File:   ZMQWorker.h
 * Author: alex
 *
 * Created on 22 Сентябрь 2016 г., 22:22
 */

#ifndef ZMQWORKER_H
#define	ZMQWORKER_H
#include <string>
#include "utils/UUID.h"
#include <zmqpp/zmqpp.hpp>
#include "easylogging++.h"
namespace rpc4stepic {
    namespace net {

        class ZMQWorker {
        public:
            ZMQWorker();
            virtual ~ZMQWorker();
            void Work(zmqpp::context* ctx, const std::string& bind_string);
        private:
            int Call(zmqpp::message* request, zmqpp::message* responce);
            std::string m_identity;
        };
    }
}

#endif	/* ZMQWORKER_H */

