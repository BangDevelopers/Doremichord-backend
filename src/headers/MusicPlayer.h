//
// Created by Azusa on 2022/4/25.
//

#ifndef DOREMICHORD_BACKEND_MUSICPLAYER_H
#define DOREMICHORD_BACKEND_MUSICPLAYER_H

extern "C" {
#include "libavcodec/avcodec.h"
#include "libavutil/avutil.h"
#include "libavutil/mem.h"
#include "libavutil/frame.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libavformat/avformat.h"
#include "libavutil/samplefmt.h"
}

#include <cstdio>
#include <string>
#include <vector>
#include <memory>


#include "MusicInfoModel.h"
#include "PlayListModel.h"

class MusicPlayer{
private:
    std::vector<std::shared_ptr<MusicInfoModel> > all_songs;
    std::vector<std::shared_ptr<PlayListModel> > all_play_lists;
public:
    MusicPlayer();
    static bool decode(std::shared_ptr<MusicInfoModel> &model);
    bool load_media_libs(std::vector<std::string> &list);
    bool sort_list(std::vector<std::shared_ptr<MusicInfoModel> > &list, std::string base);
};

#endif //DOREMICHORD_BACKEND_MUSICPLAYER_H
