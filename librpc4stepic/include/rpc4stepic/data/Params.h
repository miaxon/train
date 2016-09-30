#ifndef PARAMS_H
#define	PARAMS_H
#include <msgpack.hpp>
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class Params{
                public:
                template <typename... Args >
                Params(Args... args) {
                    msgpack::type::tuple < Args...> src(args...);
                    msgpack::pack(SerializedData, src);
                }
                virtual ~Params();
                msgpack::sbuffer SerializedData;
                private:


            };
        }
    }
}
#endif	/* PARAMS_H */