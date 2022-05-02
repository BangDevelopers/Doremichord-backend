//
// Created by Azusa on 2022/5/2.
//
#include "MediaLibLoader.h"


MediaLibModel MediaLibLoader::load(const std::string &path) {
    //遍历文件夹 获取文件列表
    std::vector<std::string> fileList;
    std::string filePath = path;
    filePath.append("/*");
    std::vector<std::string> filePathList;
    for (auto &file: filePathList) {
        if (file.find(".mp3") != std::string::npos) {
            fileList.push_back(file);
        }
    }
}