//
// Created by Azusa on 2022/5/10.
//
#include "PlayListLoader.h"

PlayListModel PlayListLoader::load(const std::string &path, std::vector<std::shared_ptr<MusicInfoModel> > &all) {
    PlayListModel model;
    Json::Value root;
    Json::Reader reader;
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return model;
    }
    if (!reader.parse(ifs, root)) {
        return model;
    }
    model.setName(root["name"].asString());
    for (auto &i: root["musics_list"]) {
        for (auto &j: all) {
            if (j->getPath() == i.asString()) {
                model.getMusicsList().push_back(i.asString());
                std::shared_ptr<MusicInfoModel> tmp = std::shared_ptr<MusicInfoModel>(j);
                model.musics.emplace_back(tmp);
            }
        }
    }
    return model;
}