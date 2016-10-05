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
#include "net/ZMQServer.h"
#include "net/ZMQClient.h"
#include "rpc/local/Sample.h"
#include "Defines.h"

#include "easylogging++.h"
using namespace std;
using namespace rpc4stepic;

/*
 * 
 */
INITIALIZE_EASYLOGGINGPP

static std::string endpoint_local("tcp://127.0.0.1:3333");
void
log_config()
{
  el::Loggers::reconfigureAllLoggers(el::ConfigurationType::Format, "%datetime <%level> %func [%loc] %msg");
}
void test_rpc() {

    net::ZMQServer srv(endpoint_local);
    cout << "Sapmle remote call Test(10, \"hello\", false)" << endl;
    rpc::local::Sample o(endpoint_local, std::string("Sample"));
    std::string s = o.Test(10, std::string("hello"), false);
    cout << "Result: " << s << endl;
}

int main(int argc, char** argv) {
    START_EASYLOGGINGPP(argc, argv);
    log_config();
    test_rpc();
    
}

