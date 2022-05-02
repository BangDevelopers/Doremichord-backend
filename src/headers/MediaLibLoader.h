//
// Created by Azusa on 2022/5/2.
//

#ifndef DOREMICHORD_BACKEND_MEDIALIBLOADER_H
#define DOREMICHORD_BACKEND_MEDIALIBLOADER_H


#include <string>
#include <vector>
#include <list>
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
    static MediaLibModel load(const std::string &path);

    static std::vector<std::string> getFiles(const std::string &path);
};

#endif //DOREMICHORD_BACKEND_MEDIALIBLOADER_H
