/* 
 * File:   main.cpp
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:22
 */

#include <cstdlib>
#include <iostream>
#include "easylogging++.h"
#include "rpc/FileSystem.h"
using namespace std;
using namespace rpc4stepic;
/*
 * 
 */
INITIALIZE_EASYLOGGINGPP

int main(int argc, char** argv) {

    rpc::FileSystem o;
    
    LOG(INFO) << o.MakeDir("");
    return 0;
}

