//
// Created by Azusa on 2022/4/27.
//

#ifndef DOREMICHORD_BACKEND_FILELOADER_H
#define DOREMICHORD_BACKEND_FILELOADER_H

#include <string>
#include "base/BaseModel.h"
#include "base/ModelRegister.h"

class FileLoader{
public:
    static std::string load(const std::string &path,const int model_type);
};

#endif //DOREMICHORD_BACKEND_FILELOADER_H
