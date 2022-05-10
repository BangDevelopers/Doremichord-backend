//
// Created by Azusa on 2022/5/2.
//

#ifndef DOREMICHORD_BACKEND_MEDIALIBMODEL_H
#define DOREMICHORD_BACKEND_MEDIALIBMODEL_H

#include <string>
#include <vector>
#include "json.h"
#include "base/BaseModel.h"

class MediaLibModel :public BaseModel{
protected:
    std::string path;
    std::vector<std::string> musics_list;
    std::vector<std::string> lrcs_list;
    int musics_count;

public:

    friend class MediaLibLoader;

    const std::vector<std::string> &getMusicsList() const;

    std::string serialization() override;

    bool construction(std::string serialized_text) override;

    ~MediaLibModel();

};

#endif //DOREMICHORD_BACKEND_MEDIALIBMODEL_H
