/* 
 * File:   Header.h
 * Author: alexcon
 *
 * Created on 3 Октябрь 2016 г., 11:06
 */

#ifndef HEADER_H
#define	HEADER_H
#include <uuid/uuid.h>
#include <msgpack.hpp>
#include "../utils/UUID.h"
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class Header {
            public:

                Header() {
                }

                Header(std::string& caller) : m_caller(caller), m_uuid(utils::UUID::GetUUIDString()) {

                }

                Header(const void* data, size_t size) {
                    msgpack::unpacked msg = msgpack::unpack(static_cast<const char*> (data), size);
                    msg.get().convert(*this);

                }
                virtual ~Header(){};
                std::string& Caller(){
                    return m_caller;
                }
                char* data() {
                    m_sbuf.clear();
                    msgpack::pack(m_sbuf, *this);
                    return m_sbuf.data();
                }

                size_t size() {
                    return m_sbuf.size();
                }

                std::string& uuid() {
                    return m_uuid;
                }

                int error() {
                    return m_error;
                }
                MSGPACK_DEFINE(m_caller, m_error, m_uuid);
            private:
                msgpack::sbuffer m_sbuf;
                std::string m_caller;
                int m_error;
                std::string m_uuid;



            };
        }
    }
}


#endif	/* HEADER_H */

