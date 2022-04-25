//
// Created by Azusa on 2022/4/25.
//

#ifndef DOREMICHORD_BACKEND_MUSICINFOMODEL_H
#define DOREMICHORD_BACKEND_MUSICINFOMODEL_H

#include <string>
#include "json.h"
#include "base/BaseModel.h"




class MusicInfoModel :public BaseModel{
protected:
    std::string artist;
    std::string title;
    std::string album;
    std::string composer;
    std::string path;
    std::string cover_path;
    int sample_rate;
    int bit_rate;
    int length;
public:
    MusicInfoModel();

    std::string serialization() override;

    bool construction(const std::string serialized_text) override;

    ~MusicInfoModel() override;

    template<typename T> T& findAttributeByName(std::string name);
};

#endif //DOREMICHORD_BACKEND_MUSICINFOMODEL_H
