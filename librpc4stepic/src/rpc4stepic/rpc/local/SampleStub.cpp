/* 
 * File:   FileSystem.cpp
 * Author: alex
 * 
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#include "rpc/local/SampleStub.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            SampleStub::SampleStub(zmqpp::endpoint_t& endpoint) : Stub(endpoint) {
            }


            SampleStub::~SampleStub() {
            }
            std::string SampleStub::SampleMethod(int i, bool b, std::string s){                
                data::Tuple parms(i, b, s);
                if( Call(std::string(__PRETTY_FUNCTION__), parms))
                {
                    msgpack::type::tuple<std::string > src;
                    msgpack::unpack(static_cast<const char*>(TupleData()), TupleSize()).get().convert(src);
                    return src.get<0>();

                }
                return std::string("");
            }
        }
    }
}
