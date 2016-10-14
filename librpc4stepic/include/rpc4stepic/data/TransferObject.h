/* 
 * File:   TransferObject.h
 * Author: alexcon
 *
 * Created on 4 Октябрь 2016 г., 16:06
 */

#ifndef TRANSFEROBJECT_H
#define	TRANSFEROBJECT_H
#include <msgpack.hpp>
#include <zmqpp/zmqpp.hpp>
#include "utils/UUID.h"
/*
 Transfer object contains three parts (zmq - frames): 
 * metadata - remote method for call and metadata, 
 * tuple - remote call parameters and response objects,  
 * raw data for transfer to 
 * and any methods for msgpack serialization/deserialization.
 * 
 */
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class MetaData {
            public:

                MetaData() {
                }

                MetaData(std::string rclass, std::string rmethod) :
                m_remote_class(rclass),
                m_remote_method(rmethod),
                m_uuid(utils::UUID::GetUUIDString()) {
                }

                virtual ~MetaData() {
                    
                    
                }

                std::string& remote_class() {
                    return m_remote_class;
                }

                std::string& remote_method() {
                    return m_remote_method;
                }

                std::string& uuid() {
                    return m_uuid;
                }
            private:
                std::string m_remote_class;
                std::string m_remote_method;
                std::string m_uuid;
            public:
                MSGPACK_DEFINE(m_remote_class, m_remote_method, m_uuid);
            };

            class TransferObject {
            public:

                TransferObject() :
                m_sbuf_meta(),
                m_sbuf_parms(),
                m_raw_data(nullptr),
                m_raw_size(0),
                m_msg() {
                };

                TransferObject(zmqpp::message& msg) :
                m_sbuf_meta(),
                m_sbuf_parms(),
                m_raw_data(nullptr),
                m_raw_size(0) {
                    m_msg.copy(msg);
                };

                virtual ~TransferObject() {
                };

                void SetMetaData(MetaData& md) {
                    msgpack::pack(m_sbuf_meta, md);
                }

                template <typename... Args >
                void SetTuple(Args... args) {
                    msgpack::type::tuple < Args...> tuple(args...);
                    msgpack::pack(m_sbuf_parms, tuple);
                }

                void SetRawData(const void* data, size_t size) {
                    m_raw_data = data;
                    m_raw_size = size;
                }

                void SetMessage(zmqpp::message& msg) {
                    m_msg.copy(msg);
                }

                template <typename... Args >
                MetaData GetMetaData() {
                    msgpack::unpacked msg = msgpack::unpack(static_cast<const char*> (m_msg.raw_data(0)), m_msg.size(0));
                    MetaData md;
                    
                    try {
                        msg.get().convert(md);
                    } catch (msgpack::type_error& err) {
                    }
                    return md;
                }

                template <typename... Args >
                msgpack::type::tuple < Args...> GetTuple() {
                    msgpack::unpacked msg = msgpack::unpack(static_cast<const char*> (m_msg.raw_data(1)), m_msg.size(1));
                    msgpack::type::tuple < Args...> tuple;
                    try {
                        msg.get().convert(tuple);
                    } catch (msgpack::type_error& err) {
                    }
                    return tuple;
                }

                const void* GetRawData() {
                    return m_msg.raw_data(2);
                }

                size_t GetRawDataSize() {
                    return m_msg.size(2);
                }

                void GetMessage(zmqpp::message& msg) {
                    msg.add_raw(m_sbuf_meta.data(), m_sbuf_meta.size());
                    msg.add_raw(m_sbuf_parms.data(), m_sbuf_parms.size());
                    msg.add_raw(m_raw_data, m_raw_size);
                }

            private:
                msgpack::sbuffer m_sbuf_meta;
                msgpack::sbuffer m_sbuf_parms;
                const void* m_raw_data;
                size_t m_raw_size;
                zmqpp::message m_msg;
            };
        }
    }
}

#endif	/* TRANSFEROBJECT_H */

