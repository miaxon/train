/* 
 * File:   UUID.h
 * Author: alexcon
 *
 * Created on 28 Сентябрь 2016 г., 16:07
 */

#ifndef UUID_H
#define	UUID_H
#include <cstdlib>
#include <uuid/uuid.h>
#include <string>
class UUID {
public:
    UUID();
    UUID(const UUID& orig);
    virtual ~UUID();
    static std::string GetUUIDString();
private:

};

#endif	/* UUID_H */

