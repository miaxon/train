/* 
 * File:   Error.h
 * Author: alex
 *
 * Created on 22 Сентябрь 2016 г., 22:38
 */

#ifndef ERROR_H
#define	ERROR_H
#include <cstdlib>
#include <string>
//#include "../easylogging++.h"
namespace rpc4stepic {

    class Error {
    public:
        Error(int code = 0, std::string message = "");
        Error(const Error& orig);
        virtual ~Error();

        bool OK() {
            return m_code == 0;
        }

        bool FAIL() {
            return m_code != 0;
        }

        std::string message() const {
            return m_message;
        }

        int code() const {
            return m_code;
        }
    private:
        int m_code;
        std::string m_message;
    };

    /*inline MAKE_LOGGABLE(Error, obj, os) {
        os << "*ERROR* {code:" << obj.code() << ", message:" << obj.message() << "}";
        return os;
    }*/
}
#endif	/* ERROR_H */

