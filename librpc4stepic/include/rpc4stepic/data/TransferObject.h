/* 
 * File:   TransferObject.h
 * Author: alexcon
 *
 * Created on 4 Октябрь 2016 г., 16:06
 */

#ifndef TRANSFEROBJECT_H
#define	TRANSFEROBJECT_H
#include <msgpack.hpp>
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class TransferObject {
            public:
                TransferObject();                
                virtual ~TransferObject();
                
            private:
                TransferObject(const TransferObject& orig);
                msgpack::sbuffer m_sbuf_meta;
                msgpack::sbuffer m_sbuf_parms;
            };
        }
    }

#endif	/* TRANSFEROBJECT_H */

