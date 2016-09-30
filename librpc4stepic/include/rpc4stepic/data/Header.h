#ifndef HEADER_H
#define	HEADER_H
#include <msgpack.hpp>
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class Header {
            public:

                Header(const string& invokeClass, const string& invokeMethod) {
                    msgpack::pack(SerializedData, *this);
                }
                Header(const Header& orig);
                virtual ~Header();
                std::string InvokeClass;
                std::string InvokeMethod;
                msgpack::sbuffer SerializedData;
                MSGPACK_DEFINE(InvokeClass, InvokeMethod);


            };
        }
    }
}
#endif	/* HEADER_H */