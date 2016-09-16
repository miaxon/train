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
#include "RPCObject.h"

namespace rpc4stepic {

    class RPCFileSystem : public RPCObject {
    public:
        RPCFileSystem();
        RPCFileSystem(const RPCFileSystem& orig);
        virtual ~RPCFileSystem();
        int MakeDir(const std::string& path);
    private:

    };
}
#endif	/* FILESYSTEM_H */
