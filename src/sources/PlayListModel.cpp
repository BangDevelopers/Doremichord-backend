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
            musics.append(music->serialization());
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
    }
    return true;
}