//
// Created by Azusa on 2022/5/9.
//
#include "PlayListModel.h"

std::string PlayListModel::serialization() {
    Json::Value root;
    root["name"] = name;
    if (!musics_list.empty()) {
        Json::Value musics;
        for (auto &music: musics_list) {
            musics.append(music);
        }
        root["musics"] = musics;
    }
    return root.toStyledString();
}

bool PlayListModel::construction(std::string serialized_text) {
    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(serialized_text, root)) {
        return false;
    }
    name = root["name"].asString();
    Json::Value musics = root["musics"];
    for (auto &music: musics) {
        musics_list.push_back(music.asString());
    }
    return true;
}

const std::string &PlayListModel::getName() const {
    return name;
}

 std::vector<std::string> &PlayListModel::getMusicsList() {
    return musics_list;
}

void PlayListModel::setName(const std::string &name) {
    PlayListModel::name = name;
}

