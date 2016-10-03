/* 
 * File:   RawData.h
 * Author: alex
 *
 * Created on 1 Октябрь 2016 г., 21:57
 */

#ifndef RAWDATA_H
#define	RAWDATA_H
namespace rpc4stepic {
    namespace rpc {
        namespace data {

            class RawData {
            public:

                RawData(char* buf, size_t size) :m_buf(buf), m_size(size) {
                    
                }
                virtual ~RawData();

                char* data() {
                    return m_buf;
                }

                size_t size() {
                    return m_size;
                }
            private:
                char* m_buf;
                size_t m_size;

            };
        }
    }
}


#endif	/* RAWDATA_H */

