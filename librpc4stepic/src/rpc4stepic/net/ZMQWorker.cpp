/* 
 * File:   ZMQWorker.cpp
 * Author: alex
 * 
 * Created on 22 Сентябрь 2016 г., 22:22
 */

#include "net/ZMQWorker.h"
namespace rpc4stepic {
    namespace net {

        ZMQWorker::ZMQWorker() {
            m_identity = utils::UUID::GetUUIDString();
        }

        ZMQWorker::~ZMQWorker() {
        }

        void ZMQWorker::Work(zmqpp::context* ctx, const std::string& bind_string) {
            zmqpp::socket worker(*ctx, zmqpp::socket_type::rep);
            worker.connect(bind_string);
            try {
                while (true) {
                    zmqpp::message req, rsp;
                    worker.receive(req);
                    Call(&req, &rsp);
                    worker.send(rsp);
                }
            } catch (std::exception &e) {
            }
        }
        int ZMQWorker::Call(zmqpp::message* request, zmqpp::message* responce){
            
        }
    }
}
