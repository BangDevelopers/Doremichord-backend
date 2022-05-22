//
// Created by RCGss on 2022/5/12.
//

#ifndef DOREMICHORD_BACKEND_USERFILE_H
#define DOREMICHORD_BACKEND_USERFILE_H

#include <string>

class UserFile{
public:
    bool user_login(std::string username,std::string password);
    bool user_register(std::string username,std::string password);
    bool user_fgpassword(std::string username,std::string password,std::string password_new);
private:

};

#endif //DOREMICHORD_BACKEND_USERFILE_H
