/* 
 * File:   Caller.h
 * Author: alexcon
 *
 * Created on 14 Октябрь 2016 г., 14:49
 */

#ifndef CALLER_H
#define	CALLER_H
#include <cstdio>
#include <cstdlib>

#include "../../data/TransferObject.h"

namespace rpc4stepic {
    namespace rpc {
        namespace remote {

            class Caller {
                typedef void (Caller::*func_t)(data::TransferObject& o);
                typedef std::map<std::string, func_t> FuncMap;
            public:

                Caller() {
                    m_func_map["Sample"] = &Caller::Call_Sample;

                }

                virtual ~Caller() {
                }

                RPC_FUNC(CallFunc) {

                    data::MetaData md = o.GetMetaData();
                    func_t fn = m_func_map[md.remote_class()];
                    if (fn)
                        (this->*fn)(o);
                    else {

                    }

                }
            private:
                FuncMap m_func_map;
                // RPC_FUNC

                RPC_FUNC(Call_Sample) {

                }
            };
        }
    }
}


#endif	/* CALLER_H */

