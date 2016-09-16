/* 
 * File:   ZMQClient.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 9:49
 */

#ifndef ZMQCLIENT_H
#define	ZMQCLIENT_H
#include <cstdlib>
#include <string>

#include "Request.h"
namespace net {

    class __attribute__((visibility("hidden"))) ZMQClient {
    public:
        ZMQClient();
        ZMQClient(const ZMQClient& orig);
        virtual ~ZMQClient();
        int Send(const serialize::Request&);
    private:
        int Connect(const std::string& server_string);
        int Send(void* data);
        int Disconnect();
    };
}
#endif	/* ZMQCLIENT_H */

