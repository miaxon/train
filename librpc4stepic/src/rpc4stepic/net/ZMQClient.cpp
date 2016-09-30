/* 
 * File:   ZMQClient.cpp
 * Author: alex
 * 
 * Created on 16 Сентябрь 2016 г., 9:49
 */

#include "net/ZMQClient.h"
namespace rpc4stepic {
    namespace net {

        ZMQClient::ZMQClient() :
        m_ctx(),
        m_socket(m_ctx, zmqpp::socket_type::req) {
        }

        ZMQClient::ZMQClient(const zmqpp::endpoint_t& endpoint) :
        m_ctx(),
        m_socket(m_ctx, zmqpp::socket_type::req),
        m_endpoint(endpoint) {
            LOG(INFO) << "Starting sender";
            m_socket.connect(m_endpoint);
        }

        ZMQClient::~ZMQClient() {
        }

        int ZMQClient::Connect(const zmqpp::endpoint_t& endpoint) {
            LOG(INFO) << "Starting sender";
            m_socket.connect(m_endpoint);
        }

        void ZMQClient::Send(const std::string& msg) {


            std::string rsp;
            m_socket.send(msg);
            m_socket.receive(rsp);

            LOG(INFO) << rsp;



        }
        int ZMQClient::Send(zmqpp::message& msg) {


            zmqpp::message rsp;
            m_socket.send(msg);
            m_socket.receive(rsp);

            //LOG(INFO) << rsp.;



        }

    }
}
