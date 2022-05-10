//
// Created by Azusa on 2022/5/2.
//
#include "MediaLibLoader.h"


std::shared_ptr<MediaLibModel> MediaLibLoader::load(const std::string &path) {
    std::filesystem::path p(path);
    if (!std::filesystem::exists(p)) {
        throw std::runtime_error("Dir not found: " + path);
    }
    if (!std::filesystem::is_directory(p)) {
        throw std::runtime_error("Not a directory: " + path);
    }
    std::shared_ptr<MediaLibModel> model = std::make_shared<MediaLibModel>();
    model->path = p.string();
    for (auto &entry: std::filesystem::recursive_directory_iterator(p)) {
        if (entry.is_regular_file()) {
            for (auto &s: supported_music_formats) {
                if (entry.path().extension() == s) {
                    model->musics_list.emplace_back(
                            entry.path().string());
                    model->musics_count += 1;
                    break;
                }
            }
            if (entry.path().extension() == ".lrc") {
                model->lrcs_list.emplace_back(entry.path().string());
            }
        }
    }
    return model;
}