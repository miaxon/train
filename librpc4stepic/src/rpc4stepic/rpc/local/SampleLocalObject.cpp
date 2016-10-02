/* 
 * File:   FileSystem.cpp
 * Author: alex
 * 
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#include "rpc/local/SampleLocalObject.h"
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            SampleLocalObject::SampleLocalObject(zmqpp::endpoint_t& endpoint) : LocalObject(endpoint) {
            }


            SampleLocalObject::~SampleLocalObject() {
            }
            int SampleLocalObject::SampleMethod(int i, bool b, std::string s){
                data::Tuple header(std::string(""), std::string(""));
                data::Tuple parms(i, b, s);
                Call(header, parms);
            }
        }
    }
}
