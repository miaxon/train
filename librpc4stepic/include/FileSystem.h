/* 
 * File:   FileSystem.h
 * Author: alex
 *
 * Created on 15 Сентябрь 2016 г., 21:34
 */

#ifndef FILESYSTEM_H
#define	FILESYSTEM_H
namespace rpc4stepic {

    class FileSystem {
    public:
        FileSystem();
        FileSystem(const FileSystem& orig);
        virtual ~FileSystem();
        int Test();
    private:

    };
}
#endif	/* FILESYSTEM_H */
