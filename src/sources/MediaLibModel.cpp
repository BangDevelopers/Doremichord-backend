//
// Created by Azusa on 2022/5/2.
//
#include "MediaLibModel.h"


std::string MediaLibModel::serialization() {
    Json::Value root;
    root["path"] = this->path;
    root["musics_count"] = this->musics_count;
    Json::Value music_list;
    for (auto &music: this->musics_list) {
        music_list.append(music);
    }
    root["musics_list"] = music_list;
    Json::Value lrcs_list;
    for (auto &lrc: this->lrcs_list) {
        lrcs_list.append(lrc);
    }
    root["lrcs_list"] = lrcs_list;
    return root.toStyledString();
}


bool MediaLibModel::construction(const std::string serialized_text) {
    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(serialized_text, root)) {
        return false;
    }
    this->path = root["path"].asString();
    this->musics_count = root["musics_count"].asInt();
    Json::Value music_list = root["musics_list"];
    for (auto &music: music_list) {
        this->musics_list.emplace_back(music.asString());
    }
    Json::Value lrcs_list = root["lrcs_list"];
    for (auto &lrc: lrcs_list) {
        this->lrcs_list.emplace_back(lrc.asString());
    }
    return true;
}

MediaLibModel::~MediaLibModel() {
    this->musics_list.clear();
    this->lrcs_list.clear();
}

const std::vector<std::string> &MediaLibModel::getMusicsList() const {
    return musics_list;
}
