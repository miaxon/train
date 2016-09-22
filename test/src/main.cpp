/* 
 * File:   main.cpp
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:22
 */

#include <cstdlib>
#include <iostream>
#include "rpc/FileSystem.h"
using namespace std;
using namespace rpc4stepic;
/*
 * 
 */
int main(int argc, char** argv) {

    rpc::FileSystem o;
    
    cout << "Hello" << " " << o.MakeDir("") << endl;
    return 0;
}

