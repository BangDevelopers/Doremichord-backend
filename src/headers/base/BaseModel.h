//
// Created by Azusa on 2022/4/24.
//

#ifndef DOREMICHORD_BACKEND_BASEMODEL_H

#include <vector>
#include <string>
#include "ModelRegister.h"

class BaseModel {
protected:
    bool serializable;
public:
    virtual std::string serialization() = 0;

    virtual bool construction(std::string serialized_text) = 0;



};



#define DOREMICHORD_BACKEND_BASEMODEL_H

#endif //DOREMICHORD_BACKEND_BASEMODEL_H
