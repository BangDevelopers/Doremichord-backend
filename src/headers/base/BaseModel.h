//
// Created by Azusa on 2022/4/24.
//

#ifndef DOREMICHORD_BACKEND_BASEMODEL_H

#include <vector>
#include <string>
#include "ModelRegister.h"

class BaseModel {
private:
    static std::vector<std::string> Variable_names;
    static int Model_type;
protected:
    bool serializable;
public:
    virtual std::string serialization() = 0;

    virtual bool construction(const std::string serialized_text) = 0;

    virtual ~BaseModel() = 0;

    virtual void findAttributeByName(const std::string name) = 0;

};

int BaseModel::Model_type = TYPE_BASE_MODEL;


#define DOREMICHORD_BACKEND_BASEMODEL_H

#endif //DOREMICHORD_BACKEND_BASEMODEL_H
