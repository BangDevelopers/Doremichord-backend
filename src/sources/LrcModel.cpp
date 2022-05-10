//
// Created by Azusa on 2022/5/2.
//
#include "LrcModel.h"






LrcModel::LrcModel() {}

std::string LrcModel::serialization() {
    Json::Value root;
    root["lrc_path"] = lrc_path;
    Json::Value lrc_l;
    for (auto &l: lrc_list) {
        Json::Value lrc_l_item;
        lrc_l_item["time"] = l.first;
        lrc_l_item["content"] = l.second;
        lrc_l.append(lrc_l_item);
    }
    root["lrc_list"] = lrc_l;
    return root.toStyledString();
}

bool LrcModel::construction(const std::string serialized_text) {
    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(serialized_text, root)) {
        return false;
    }
    lrc_path = root["lrc_path"].asString();
    Json::Value lrc_l = root["lrc_list"];
    for (auto &l: lrc_l) {
        lrc_list.emplace_back(std::pair<int, std::string>(l["time"].asInt(), l["content"].asString()));
    }
    return true;
}

LrcModel::~LrcModel() {
    lrc_list.clear();
}


const std::string &LrcModel::getLrcPath() const {
    return lrc_path;
}

void LrcModel::setLrcPath(const std::string &lrcPath) {
    lrc_path = lrcPath;
}

const std::vector<std::pair<int, std::string>> &LrcModel::getLrcList() {
    return lrc_list;
}

void LrcModel::setLrcList(const std::vector<std::pair<int, std::string>> &lrcList) {
    lrc_list = lrcList;
}

void LrcModel::add(int time, std::string lrc) {
    lrc_list.emplace_back(std::pair<int, std::string>(time, lrc));
}