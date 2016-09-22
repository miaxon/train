/* 
 * File:   ZMQServer.cpp
 * Author: alexcon
 * 
 * Created on 22 Сентябрь 2016 г., 17:21
 */

#include "net/ZMQServer.h"

namespace rpc4stepic {
    namespace net {

        ZMQServer::ZMQServer() :
        m_frontend(m_ctx, zmqpp::socket_type::router),
        m_backend(m_ctx, zmqpp::socket_type::dealer),
        m_num_workers(2) {
        }


        ZMQServer::~ZMQServer() {
        }

        Error ZMQServer::StartLocal() {
            m_frontend.bind(LOCAL_FRONTEND);
            m_backend.bind(LOCAL_BACKEND);
            std::vector<ZMQWorker *> workers;
            std::vector<std::thread *> worker_threads;
            for (int i = 0; i < m_num_workers; ++i) {
                workers.push_back(new ZMQWorker(m_ctx));
                worker_threads.push_back(new std::thread(std::bind(&ZMQWorker::Work, workers[i], LOCAL_BACKEND)));
                worker_threads[i]->detach();
            }


            try {
                zmqpp::proxy(m_frontend, m_backend, nullptr);
            } catch (std::exception &e) {
            }

            for (int i = 0; i < m_num_workers; ++i) {
                delete workers[i];
                delete worker_threads[i];
            }
        }
    }
}
