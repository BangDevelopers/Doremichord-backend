//
// Created by Azusa on 2022/5/2.
//
#include "MediaLibModel.h"

void MediaLibModel::InitModel() {
    MediaLibModel::Model_type = TYPE_MEDIA_LIB_MODEL;
    MediaLibModel::Variable_names = std::vector<std::string>();
    MediaLibModel::Variable_names.emplace_back("path");
    MediaLibModel::Variable_names.emplace_back("musics_list");
    MediaLibModel::Variable_names.emplace_back("lrcs_list");
    MediaLibModel::Variable_names.emplace_back("musics_count");
}

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
}

template <typename T>T& MediaLibModel::findAttributeByName(std::string name) {
    if (name == "path") {
        return this->path;
    } else if (name == "musics_count") {
        return this->musics_count;
    } else if (name == "musics_list") {
        return this->musics_list;
    } else if (name == "lrcs_list") {
        return this->lrcs_list;
    } else {
        return T();
    }
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
