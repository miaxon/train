#ifndef PARAMS_H
#define	PARAMS_H
#include <msgpack.hpp>
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class params {
            public:

                template <typename... Args >
                params(Args... args) {
                    msgpack::type::tuple < Args...> tuple(args...);
                    msgpack::pack(m_sbuf, tuple);
                }
                virtual ~params();

                char* data() {
                    return m_sbuf.data();
                }

                size_t size() {
                    return m_sbuf.size();
                }
            private:
                msgpack::sbuffer m_sbuf;

            };
        }
    }
}
#endif	/* PARAMS_H */