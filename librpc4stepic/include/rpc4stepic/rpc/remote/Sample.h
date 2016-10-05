/* 
 * File:   Sample.h
 * Author: alexcon
 *
 * Created on 5 Октябрь 2016 г., 13:00
 */

#ifndef SAMPLE_H
#define	SAMPLE_H
#include "data/TransferObject.h"
typedef msgpack::type::tuple<std::string, std::string, std::string> metadata;
namespace rpc4stepic {
    namespace rpc {
        namespace local {

            class Sample {
            public:
                Sample();
                virtual ~Sample();

                void Sample(data::TransferObject& tr_object) {
                    metadata meta = tr_object.GetMetaData<std::string, std::string, std::string>()
                }
            private:

            };
        }
    }

#endif	/* SAMPLE_H */

