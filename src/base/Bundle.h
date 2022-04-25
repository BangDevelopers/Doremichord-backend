//
// Created by Azusa on 2022/4/24.
//

#ifndef DOREMICHORD_BACKEND_BUNDLE_H
#define DOREMICHORD_BACKEND_BUNDLE_H

#include <memory>
#include <utility>
#include "BaseModel.h"

class Bundle {
protected:
    unsigned int action_code;
    std::shared_ptr<BaseModel> data_model;
public:
    Bundle(unsigned int actionCode, std::shared_ptr<BaseModel> dataModel) : action_code(actionCode),
                                                                                   data_model(std::move(dataModel)) {}

    [[nodiscard]] unsigned int getActionCode() const {
        return action_code;
    }

    [[nodiscard]] const std::shared_ptr<BaseModel> &getDataModel() const {
        return data_model;
    }

    ~Bundle()= default;
};

#endif //DOREMICHORD_BACKEND_BUNDLE_H
