//
// Created by Azusa on 2022/5/9.
//

#ifndef DOREMICHORD_BACKEND_PLAYLISTLOADER_H
#define DOREMICHORD_BACKEND_PLAYLISTLOADER_H

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "json.h"
#include "MusicInfoModel.h"
#include "PlayListModel.h"

class PlayListLoader {
public:
    static PlayListModel load(const std::string &path,std::vector<std::shared_ptr<MusicInfoModel> > &all);
};

#endif //DOREMICHORD_BACKEND_PLAYLISTLOADER_H
