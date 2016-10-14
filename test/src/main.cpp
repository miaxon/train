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

using namespace std;
using namespace rpc4stepic;

/*
 * 
 */
static std::string endpoint_local("tcp://127.0.0.1:3333");
static net::ZMQServer srv(endpoint_local);
void test_rpc() {

    std::thread::id id = std::this_thread::get_id();

    cout << "Sapmle remote call Test(10, \"hello\", false)" << endl;
    rpc::local::Sample o(endpoint_local, std::string("Sample"));
    for (int i = 0; i < 3; i++) {
        std::string s = o.Test(10, std::string("hello"), false);
        cout << "[" << id << "]" << "Result: " << s << endl;
    }
}

int main(int argc, char** argv) {

    test_rpc();
}

