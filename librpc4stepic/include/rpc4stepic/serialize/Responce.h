/* 
 * File:   Responce.h
 * Author: alex
 *
 * Created on 16 Сентябрь 2016 г., 11:26
 */

#ifndef RESPONCE_H
#define	RESPONCE_H
namespace rpc4stepic {
    namespace serialize {

        class Responce {
        public:
            Responce();
            Responce(const Responce& orig);
            virtual ~Responce();
            int int_result;
            int error;
        private:

        };
    }
}
#endif	/* RESPONCE_H */

