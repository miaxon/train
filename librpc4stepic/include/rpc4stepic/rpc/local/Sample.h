/* 
 * File:   Sample.h
 * Author: alexcon
 *
 * Created on 5 Октябрь 2016 г., 12:43
 */

#ifndef SAMPLE_H
#define	SAMPLE_H
#include <msgpack.hpp>
#include "net/ZMQClient.h"
#include "data/TransferObject.h"
#include "utils/UUID.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            class Sample {
            public:

                Sample(zmqpp::endpoint_t& endpoint, std::string remote_class) : m_client(endpoint), m_remote_class(remote_class) {
                }

                std::string Test(int i, std::string s, bool b) {
                    std::string remote_method("Test");
                    data::MetaData md(m_remote_class, remote_method);
                    data::TransferObject tr_object;
                    tr_object.SetMetaData(md);
                    tr_object.SetTuple(i, s, b);
                    m_client.Send(tr_object);
                    msgpack::type::tuple<std::string> tuple = tr_object.GetTuple<std::string>();
                    std::string result = tuple.get<0>();
                    return result;
                }

                virtual ~Sample() {
                };
            private:
                net::ZMQClient m_client;
                std::string m_remote_class;
            };
        }
    }
}
#endif	/* SAMPLE_H */

