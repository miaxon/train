#ifndef PARAMS_H
#define	PARAMS_H
#include <msgpack.hpp>
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class Tuple {
            public:

                template <typename... Args >
                Tuple(Args... args) {
                    msgpack::type::tuple < Args...> tuple(args...);
                    msgpack::pack(m_sbuf, tuple);
                }
                virtual ~Tuple(){};

                char* data() {
                    return m_sbuf.data();
                }

                size_t size() {
                    return m_sbuf.size();
                }
                template <typename... Args >
                msgpack::type::tuple < Args...> get(){
                    msgpack::unpacked msg = msgpack::unpack(m_sbuf.data(), m_sbuf.size());
                    msgpack::type::tuple < Args...> tuple;
                    msg.get().convert(tuple);
                    return tuple;
                }
            private:
                msgpack::sbuffer m_sbuf;

            };
        }
    }
}
#endif	/* PARAMS_H */