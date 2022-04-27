//
// Created by Azusa on 2022/4/27.
//

#ifndef DOREMICHORD_BACKEND_LRCMODEL_H
#define DOREMICHORD_BACKEND_LRCMODEL_H

#include <string>
#include <vector>
#include "base/BaseModel.h"
#include "base/ModelRegister.h"


class LrcModel:public BaseModel{
private:
    static std::vector<std::string> Variable_names;
    static int Model_type;
protected:
    std::string lrc_path;
public:

    static void Init_Model(){
        LrcModel::Variable_names = std::vector<std::string>();
        LrcModel::Variable_names.emplace_back("lrc_path");
    }

    std::string serialization() override {
        std::string text = std::string();
        text+="{\n";
        text+="lrc_path:";
        text+=this->lrc_path;
        text+=",";
        text+="}";
        return text;
    }

    bool construction(const std::string serialized_text) override {

    }

    ~LrcModel() override {

    }

    void findAttributeByName(const std::string name) override {

    }
};

int LrcModel::Model_type = TYPE_LRC_MODEL;

#endif //DOREMICHORD_BACKEND_LRCMODEL_H
