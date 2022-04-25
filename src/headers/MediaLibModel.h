//
// Created by Azusa on 2022/5/2.
//

#ifndef DOREMICHORD_BACKEND_MEDIALIBMODEL_H
#define DOREMICHORD_BACKEND_MEDIALIBMODEL_H

#include <string>
#include <vector>
#include "json.h"
#include "base/BaseModel.h"
#include "base/ModelRegister.h"

class MediaLibModel :public BaseModel{
private:
    static unsigned int Model_type;
    static std::vector<std::string> Variable_names;
protected:
    std::string path;
    std::vector<std::string> musics_list;
    std::vector<std::string> lrcs_list;
    int musics_count;

public:
    static void InitModel();

    std::string serialization() override;

    template<typename T> T& findAttributeByName(std::string name);

    bool construction(std::string serialized_text) override;

    ~MediaLibModel() override;

};

#endif //DOREMICHORD_BACKEND_MEDIALIBMODEL_H
