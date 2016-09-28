/* 
 * File:   ZMQWorker.cpp
 * Author: alex
 * 
 * Created on 22 Сентябрь 2016 г., 22:22
 */

#include "net/ZMQWorker.h"

ZMQWorker::ZMQWorker() {
    m_identity = UUID::GetUUIDString();
}

ZMQWorker::~ZMQWorker() {
}

void ZMQWorker::Work(zmqpp::context* ctx, const std::string& bind_string) {  
    zmqpp::socket worker(*ctx, zmqpp::socket_type::rep);
    worker.connect(bind_string);
    try {
        while (true) {
            std::string msg;
            worker.receive(msg);
            LOG(INFO) << "worker recieved " << msg;
            msg += "... yeap!";
            worker.send(msg);
        }
    } catch (std::exception &e) {
    }
}

