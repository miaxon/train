/* 
 * File:   ZMQWorker.cpp
 * Author: alex
 * 
 * Created on 22 Сентябрь 2016 г., 22:22
 */

#include "net/ZMQWorker.h"

ZMQWorker::ZMQWorker(const std::string& identity) : m_identity(identity) {
    LOG(INFO) << m_identity;
}

ZMQWorker::~ZMQWorker() {
}

void ZMQWorker::Work(zmqpp::context* ctx, const std::string& bind_string, const int identity) {
    LOG(INFO) << "Starting worker " << identity;

    zmqpp::socket worker(*ctx, zmqpp::socket_type::rep);
    worker.connect(bind_string);
    try {
        while (true) {
            std::string msg;
            worker.receive(msg);
            if(identity == 4)
               std::this_thread::sleep_for(std::chrono::milliseconds(100));
            LOG(INFO) << "worker recieved " << msg;
            msg += std::to_string(identity);
            worker.send(msg);
        }
    } catch (std::exception &e) {
    }
}

