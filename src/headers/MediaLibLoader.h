//
// Created by Azusa on 2022/5/2.
//

#ifndef DOREMICHORD_BACKEND_MEDIALIBLOADER_H
#define DOREMICHORD_BACKEND_MEDIALIBLOADER_H


#include <string>
#include <vector>
#include <list>
#include <memory>
#include <filesystem>
#include "MediaLibModel.h"

static std::list<std::string> supported_music_formats = std::list<std::string>({
                                                                                       ".mp3",
                                                                                       ".wav",
                                                                                       ".flac",
                                                                                       ".ogg",
                                                                                       ".wma",
                                                                                       ".m4a",
                                                                                       ".aac",
                                                                                       ".ape"});


class MediaLibLoader {
public:
    static std::shared_ptr<MediaLibModel> load(const std::string &path);

};

#endif //DOREMICHORD_BACKEND_MEDIALIBLOADER_H
