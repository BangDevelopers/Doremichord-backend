//
// Created by Azusa on 2022/5/6.
//
#include "MusicInfoLoader.h"

std::shared_ptr<MusicInfoModel> MusicInfoLoader::load(const std::string &path) {
    AVFormatContext *fmtCtx = nullptr;
    std::shared_ptr<MusicInfoModel> model = std::make_shared<MusicInfoModel>();
    if (avformat_open_input(&fmtCtx, path.c_str(), nullptr, nullptr) >= 0) {

        AVDictionary *metadata = fmtCtx->metadata;
        AVDictionaryEntry *avd = nullptr;

        if ((avd = av_dict_get(metadata, "TITLE", nullptr, 0))) {
            model->title = avd->value;
        }
        if ((avd = av_dict_get(metadata, "ARTIST", nullptr, 0))) {
            model->artist = avd->value;
        }
        if ((avd = av_dict_get(metadata, "ALBUM", nullptr, 0))) {
            model->album = avd->value;
        }
        if ((avd = av_dict_get(metadata, "COMPOSER", nullptr, 0))) {
            model->composer = avd->value;
        }
        if (fmtCtx->iformat->read_header(fmtCtx) >= 0) {

            for (int i = 0; i < fmtCtx->nb_streams; i++) {
                if (fmtCtx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
                    std::string file_path = ("./tmp/" + model->title + ".jpg");
                    FILE *img = fopen(
                            file_path.c_str(), "wb");
                    AVPacket pkt = fmtCtx->streams[i]->attached_pic;
                    fwrite(pkt.data, 1, pkt.size, img);
                    fclose(img);
                }
            }

            model->cover_path =
                    "./tmp/" + model->title + ".jpg";
        }
        model->path = std::string(path);
    }
    return model;
}