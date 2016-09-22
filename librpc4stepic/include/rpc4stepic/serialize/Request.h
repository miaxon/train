/* 
 * File:   Request.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 11:20
 */

#ifndef REQUEST_H
#define	REQUEST_H
#include <string>
namespace rpc4stepic {
    namespace serialize {

        class Request {
        public:
            Request();
            Request(const Request& orig);
            Request(std::string& str);
            virtual ~Request();
            std::string str_arg;

        private:

        };
    }
}
#endif	/* REQUEST_H */

