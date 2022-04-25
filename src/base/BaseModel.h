//
// Created by Azusa on 2022/4/24.
//

#ifndef DOREMICHORD_BACKEND_BASEMODEL_H

#include <string>

class BaseModel {
protected:
    std::string model_type_;
    bool serializable_;
public:
    virtual std::string Serialization() = 0;

    virtual bool Construction(std::string serialized_text) = 0;

    virtual ~BaseModel() = 0;
};


#define DOREMICHORD_BACKEND_BASEMODEL_H

#endif //DOREMICHORD_BACKEND_BASEMODEL_H
