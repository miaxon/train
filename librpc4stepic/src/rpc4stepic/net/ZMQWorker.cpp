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
            zmqpp::socket socket(*ctx, zmqpp::socket_type::rep);
            socket.connect(bind_string);
            try {
                while (true) {
                    zmqpp::message req;
                    socket.receive(req);
                    rpc::data::TransferObject tr_object(req);
                    Call(tr_object);
                    zmqpp::message rsp;
                    tr_object.GetRequestMessage(rsp);
                    socket.send(rsp);
                }
            } catch (std::exception &e) {
            }
        }

        void ZMQWorker::Call(rpc::data::TransferObject& tr_object) {
            rpc::data::MetaData md = tr_object.GetMetaData();
            LOG(INFO) << "Meta data: " << md.remote_class() << " " << md.remote_method() << " " << md.uuid();

            msgpack::type::tuple<int, std::string, bool> t = tr_object.GetTuple<int, std::string, bool>();
            int i;
            std::string s;
            bool b;
            i = t.get<0>();
            s = t.get<1>();
            b = t.get<2>();
            LOG(INFO) << "Tuple: " << i << " " << s << " " << (b ? "true" : "false");
            std::stringstream ss;
            ss << i << " " << s << " ...yeap! " << (b ? "true" : "false");
            //simple echo            
            tr_object.SetTuple(ss.str());
        }
    }
}
