/* 
 * File:   ZMQWorker.h
 * Author: alex
 *
 * Created on 22 Сентябрь 2016 г., 22:22
 */

#ifndef ZMQWORKER_H
#define	ZMQWORKER_H
#include <string>
#include <zmqpp/zmqpp.hpp>
class ZMQWorker {
public:
    ZMQWorker(zmqpp::context context);
    ZMQWorker(const ZMQWorker& orig);
    virtual ~ZMQWorker();
    void Work(const std::string& bind_string);
private:
    zmqpp::context &m_ctx;
    zmqpp::socket m_socket;
};

#endif	/* ZMQWORKER_H */

