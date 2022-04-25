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
    unsigned int action_code_;
    std::shared_ptr<BaseModel> data_model_;
public:
    Bundle(unsigned int actionCode, std::shared_ptr<BaseModel> dataModel) : action_code_(actionCode),
                                                                                   data_model_(std::move(dataModel)) {}

    [[nodiscard]] unsigned int getActionCode() const {
        return action_code_;
    }

    [[nodiscard]] const std::shared_ptr<BaseModel> &getDataModel() const {
        return data_model_;
    }

    ~Bundle()= default;
};

#endif //DOREMICHORD_BACKEND_BUNDLE_H
