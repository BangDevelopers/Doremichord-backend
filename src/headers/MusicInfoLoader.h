//
// Created by Azusa on 2022/5/6.
//

#ifndef DOREMICHORD_BACKEND_MUSICINFOLOADER_H
#define DOREMICHORD_BACKEND_MUSICINFOLOADER_H

extern "C" {
#include <libavformat/avformat.h>
}


#include <string>
#include <memory>
#include <filesystem>
#include "MusicInfoModel.h"

class MusicInfoModel;

class MusicInfoLoader {
    static std::shared_ptr<MusicInfoModel> load(const std::string &path);
};

#endif //DOREMICHORD_BACKEND_MUSICINFOLOADER_H
