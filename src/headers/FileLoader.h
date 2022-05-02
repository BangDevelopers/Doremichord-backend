//
// Created by Azusa on 2022/4/27.
//

#ifndef DOREMICHORD_BACKEND_FILELOADER_H
#define DOREMICHORD_BACKEND_FILELOADER_H

#include <string>
#include "json.h"
#include "base/BaseModel.h"
#include "base/ModelRegister.h"

class FileLoader{
public:
    bool load(const std::string &path,Json::Value &root);
    bool write(const std::string &path,const Json::Value &root);
};



#endif //DOREMICHORD_BACKEND_FILELOADER_H
