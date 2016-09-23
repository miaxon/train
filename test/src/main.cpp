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
#include "rpc/FileSystem.h"
#include "net/ZMQServer.h"
#include "net/ZMQClient.h"
#include "Defines.h"
using namespace std;
using namespace rpc4stepic;

/*
 * 
 */
INITIALIZE_EASYLOGGINGPP
static std::string endpoint_local("tcp://127.0.0.1:3333");

int main(int argc, char** argv) {

    LOG(INFO) << "Starting..";
    net::ZMQServer srv(endpoint_local);


    net::ZMQClient clt(endpoint_local);


    for(int i = 0; i< 1000000; i++)
    clt.Send("Hello!");



    return 0;
}

