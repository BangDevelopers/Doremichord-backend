//
// Created by Azusa on 2022/5/2.
//
#include <fstream>
#include <regex>
#include "LrcModel.h"
#include "LrcLoader.h"


LrcModel* LrcLoader::load(const char *path) {
    LrcModel *Model=new LrcModel();

    QFile File(path);
    

    

   QString Line;
    while (!File.atEnd()) {
        Line=File.readLine();
        Line=Line.mid(0,Line.length()-1);
        std::string line=Line.toStdString();
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
            (*Model).add(time, content);
        } else{
            Model->add(-1, line);
        }
    }

    return Model;
}
