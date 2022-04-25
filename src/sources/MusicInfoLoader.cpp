//
// Created by Azusa on 2022/5/6.
//
#include "MusicInfoLoader.h"

std::shared_ptr<MusicInfoModel> MusicInfoLoader::load(const std::string &path) {
    AVFormatContext *fmtCtx = nullptr;
    std::shared_ptr<MusicInfoModel> model = std::make_shared<MusicInfoModel>();
    if (avformat_open_input(&fmtCtx, path.c_str(), nullptr, nullptr) >= 0) {

        AVDictionary *metadata = fmtCtx->metadata;

        model->findAttributeByName<std::string>("title") = av_dict_get(metadata, "TITLE", nullptr, 0)->value;
        model->findAttributeByName<std::string>("artist") = av_dict_get(metadata, "ARTIST", nullptr, 0)->value;
        model->findAttributeByName<std::string>("album") = av_dict_get(metadata, "ALBUM", nullptr, 0)->value;
        model->findAttributeByName<std::string>("composer") = av_dict_get(metadata, "COMPOSER", nullptr, 0)->value;

        if (fmtCtx->iformat->read_header(fmtCtx) >= 0) {
            FILE *img = fopen(
                    (std::string("tmp\\") + model->findAttributeByName<std::string>("title") + ".jpg").c_str(), "wb");
            for (int i = 0; i < fmtCtx->nb_streams; i++) {
                if (fmtCtx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
                    AVPacket pkt = fmtCtx->streams[i]->attached_pic;
                    fwrite(pkt.data, 1, pkt.size, img);
                }
            }
            fclose(img);
            model->findAttributeByName<std::string>("cover_path") =
                    std::string("tmp\\") + model->findAttributeByName<std::string>("title") + ".jpg";
        }
    }
    return model;
}