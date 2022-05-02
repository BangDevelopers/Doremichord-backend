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

#include "/base/IPlayer.h"
#include "MusicInfoModel.h"

class MusicPlayer :public IPlayer {
public:
    static MusicInfoModel decode(const char *filePath,const char *outPath);
    static MusicInfoModel fill_music_info_model(AVFormatContext *fmtCtx);
};

#endif //DOREMICHORD_BACKEND_MUSICPLAYER_H