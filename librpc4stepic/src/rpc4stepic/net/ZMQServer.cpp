/* 
 * File:   ZMQServer.cpp
 * Author: alexcon
 * 
 * Created on 22 Сентябрь 2016 г., 17:21
 */

#include "net/ZMQServer.h"

namespace rpc4stepic {
    namespace net {

        ZMQServer::ZMQServer(zmqpp::endpoint_t& endpoint, int nworkers) :
        m_ctx(),
        m_frontend(m_ctx, zmqpp::socket_type::router),
        m_backend(m_ctx, zmqpp::socket_type::dealer),
        m_endpoint(endpoint),
        m_nworkers(nworkers) {
std:
            thread t(std::bind(&net::ZMQServer::run, this));
            t.detach();
        }

        ZMQServer::~ZMQServer() {

        }

        void ZMQServer::run() {

            m_frontend.bind(m_endpoint);
            std::string backend = "inproc://" + utils::UUID::GetUUIDString();
            m_backend.bind(backend);
            LOG(LOG_INFO, "Sucessfully started on %s", m_endpoint.c_str());
            for (int i = 0; i < m_nworkers; ++i) {
                ZMQWorker worker;
                std::thread worker_thread(std::bind(&ZMQWorker::Work, &worker, &m_ctx, backend));
                worker_thread.detach();
            }
            LOG(LOG_INFO, "Sucessfully started worker %d threads", m_nworkers);
            try {
                zmqpp::proxy(m_frontend, m_backend);
            } catch (std::exception &e) {
                LOG(LOG_ERR, "Failed to proxy backend: %s", e.what());
            }
        }
    }
}
