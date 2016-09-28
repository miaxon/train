/* 
 * File:   FileSystem.h
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#ifndef SAMPLE_H
#define	SAMPLE_H
#include <cstdlib>
#include <string>
#include "LocalObject.h"

namespace rpc4stepic {
    namespace rpc {
        namespace local {

            class SampleLocalObject : public LocalObject {
            public:
                SampleLocalObject();
                SampleLocalObject(const SampleLocalObject& orig);
                virtual ~SampleLocalObject();
            private:

            };
        }
    }
}
#endif	/* FILESYSTEM_H */
