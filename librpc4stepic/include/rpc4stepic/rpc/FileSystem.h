/* 
 * File:   FileSystem.h
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#ifndef FILESYSTEM_H
#define	FILESYSTEM_H
#include <cstdlib>
#include <string>
#include "BaseObject.h"

namespace rpc4stepic {
    namespace rpc {

        class FileSystem : public BaseObject {
        public:
            FileSystem();
            FileSystem(const FileSystem& orig);
            virtual ~FileSystem();
            int MakeDir(const std::string& path);
        private:

        };
    }
}
#endif	/* FILESYSTEM_H */
