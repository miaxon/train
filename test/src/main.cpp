/* 
 * File:   main.cpp
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:22
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <chrono>
#include "easylogging++.h"
#include "net/ZMQServer.h"
#include "net/ZMQClient.h"
#include "Defines.h"
#include "rpc/local/SampleLocalObject.h"
using namespace std;
using namespace rpc4stepic;

/*
 * 
 */
INITIALIZE_EASYLOGGINGPP
static std::string endpoint_local("tcp://127.0.0.1:3333");

void test_net() {
    LOG(INFO) << "Starting test net.";
    net::ZMQServer srv(endpoint_local);


    net::ZMQClient clt(endpoint_local);


    for (int i = 0; i < 10; i++)
        clt.Send("Hello!");

}

void start_srv() {
    net::ZMQServer srv(endpoint_local);

}
void test_rpc(){
    
    net::ZMQServer srv(endpoint_local);
    rpc::local::SampleLocalObject o(endpoint_local);
    o.SampleMethod(10,false,std::string("hello"));
}
int main(int argc, char** argv) {
    test_rpc();
}

