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
#include "easylogging++.h"
class ZMQWorker {
public:
    ZMQWorker(const std::string& identity);
    virtual ~ZMQWorker();
    void Work(zmqpp::context* ctx, const std::string& bind_string, const int identity);
private:
    std::string m_identity;
};

#endif	/* ZMQWORKER_H */

