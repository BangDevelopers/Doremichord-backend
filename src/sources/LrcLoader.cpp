//
// Created by Azusa on 2022/5/2.
//
#include <fstream>
#include <regex>
#include "LrcModel.h"
#include "LrcLoader.h"

LrcModel LrcLoader::load(const char *path) {
    LrcModel model;
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        std::regex regex(R"(\[(\d{2}):(\d{2})(\.(\d{2}))?](.*))");
        std::smatch match;
        if (std::regex_match(line, match, regex)) {
            int minute = std::stoi(match[1]);
            int second = std::stoi(match[2]);
            int millisecond = 0;
            if (match[4].matched) {
                millisecond = std::stoi(match[4]);
            }
            std::string content = match[5];
            int time = minute * 60 * 1000 + second * 1000 + millisecond * 10;
            model.add(time, content);
        } else{
            model.add(-1, line);
        }
    }
    return model;
}
