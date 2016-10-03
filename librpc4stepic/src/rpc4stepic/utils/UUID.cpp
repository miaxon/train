/* 
 * File:   UUID.cpp
 * Author: alexcon
 * 
 * Created on 28 Сентябрь 2016 г., 16:07
 */

#include "utils/UUID.h"
namespace rpc4stepic {
    namespace utils {

        UUID::UUID() {
        }

        UUID::UUID(const UUID& orig) {
        }

        UUID::~UUID() {
        }

        std::string UUID::GetUUIDString() {
            uuid_t uuid;
            uuid_generate(uuid);
            char uuid_str[37];
            uuid_unparse_lower(uuid, uuid_str);
            return std::string(uuid_str);
        }
    }
}