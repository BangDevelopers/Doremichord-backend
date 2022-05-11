//
// Created by Azusa on 2022/5/9.
//

#ifndef DOREMICHORD_BACKEND_PLAYLISTMODEL_H
#define DOREMICHORD_BACKEND_PLAYLISTMODEL_H

#include <memory>
#include <vector>
#include <string>
#include "json.h"
#include "MusicInfoModel.h"

class PlayListModel : public BaseModel {
protected:
    std::string name;
    std::vector<std::string> musics_list;
public:
    std::string serialization() override;

    bool construction(std::string serialized_text) override;

    [[nodiscard]] const std::string &getName() const;

    void setName(const std::string &name);

    std::vector<std::string> &getMusicsList();


};

#endif //DOREMICHORD_BACKEND_PLAYLISTMODEL_H
