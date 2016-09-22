/* 
 * File:   ZMQWorker.cpp
 * Author: alex
 * 
 * Created on 22 Сентябрь 2016 г., 22:22
 */

#include "net/ZMQWorker.h"

ZMQWorker::ZMQWorker(zmqpp::context& ctx):m_ctx(ctx), m_socket(ctx, zmqpp::socket_type::dealer) {
}

ZMQWorker::ZMQWorker(const ZMQWorker& orig) {
}

ZMQWorker::~ZMQWorker() {
}
void ZMQWorker::Work(const std::string& bind_string) {
    m_socket.connect(bind_string);
}

