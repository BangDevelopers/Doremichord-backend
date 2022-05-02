//
// Created by Azusa on 2022/4/27.
//
#include <fstream>
#include <memory>
#include "FileLoader.h"
#include "json.h"


bool FileLoader::load(const std::string &path, Json::Value &root) {
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return false;
    }
    Json::CharReaderBuilder builder;
    builder["collectComments"] = false;
    std::string errs;
    if (!Json::parseFromStream(builder, ifs, &root, &errs)) {
        return false;
    }
    return true;
}

bool FileLoader::write(const std::string &path, const Json::Value &root) {
    std::ofstream ofs(path);
    if (!ofs.is_open()) {
        return false;
    }
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(root, &ofs);
    return true;
}