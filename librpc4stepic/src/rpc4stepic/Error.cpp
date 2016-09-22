/* 
 * File:   Error.cpp
 * Author: alex
 * 
 * Created on 22 Сентябрь 2016 г., 22:38
 */

#include "Error.h"
namespace rpc4stepic {

    Error::Error(int code, std::string message):m_code(code),m_message(message) {
    }

    Error::Error(const Error& orig) {
    }

    Error::~Error() {
    }
}

