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
            m_socket.connect(m_endpoint);
        }

        ZMQClient::~ZMQClient() {
        }

        void ZMQClient::Send(rpc::data::TransferObject& tr_object) {            
            zmqpp::message req;
            tr_object.GetRequestMessage(req);
            m_socket.send(req);
            zmqpp::message rsp;
            m_socket.receive(rsp);
            tr_object.SetResponceMessage(rsp);
        }

    }
}
