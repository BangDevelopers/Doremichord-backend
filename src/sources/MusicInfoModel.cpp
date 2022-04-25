//
// Created by Azusa on 2022/5/6.
//
#include "MusicInfoModel.h"

MusicInfoModel::MusicInfoModel() {}

template<typename T>
T& MusicInfoModel::findAttributeByName(std::string name) {
    if (name == "artist") {
        return artist;
    } else if (name == "title") {
        return title;
    } else if (name == "album") {
        return album;
    } else if (name == "composer") {
        return composer;
    } else if (name == "path") {
        return path;
    } else if (name == "cover_path") {
        return cover_path;
    } else if (name == "sample_rate") {
        return sample_rate;
    } else if (name == "bit_rate") {
        return bit_rate;
    } else if (name == "length") {
        return length;
    } else {
        return "";
    }
}

std::string MusicInfoModel::serialization() {
    Json::Value root;
    root["artist"] = artist;
    root["title"] = title;
    root["album"] = album;
    root["composer"] = composer;
    root["path"] = path;
    root["cover_path"] = cover_path;
    root["sample_rate"] = sample_rate;
    root["bit_rate"] = bit_rate;
    root["length"] = length;
    return root.toStyledString();
}

bool MusicInfoModel::construction(const std::string serialized_text) {
    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(serialized_text, root)) {
        return false;
    }
    artist = root["artist"].asString();
    title = root["title"].asString();
    album = root["album"].asString();
    composer = root["composer"].asString();
    path = root["path"].asString();
    cover_path = root["cover_path"].asString();
    sample_rate = root["sample_rate"].asInt();
    bit_rate = root["bit_rate"].asInt();
    length = root["length"].asInt();
    return true;
}

MusicInfoModel::~MusicInfoModel() {}
