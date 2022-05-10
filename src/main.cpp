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

#include <iostream>
#include <filesystem>
#include <string>
#include <direct.h>
#include <vector>
#include <iconv.h>
#include "json.h"
#include "MusicInfoLoader.h"
#include "MediaLibLoader.h"

using namespace std;

#define MAX_AUDIO_FRAME_SIZE 384000


int main() {
//    std::shared_ptr<MediaLibModel> p = MediaLibLoader::load("./");
//    if (p != nullptr) {
//        for (auto &m: p->getMusicsList()) {
//            std::shared_ptr<MusicInfoModel> mp = MusicInfoLoader::load(m);
//            cout << mp->serialization()<< endl;
//        }
//    }
    std::string s= "Ring of Fortune(TV\u30a2\u30cb\u30e1\u300c\u30d7\u30e9\u30b9\u30c6\u30a3\u30c3\u30af\u30fb\u30e1\u30e2\u30ea\u30fc\u30ba\u300d\u30aa\u30fc\u30d7\u30cb\u30f3\u30b0\u30c6\u30fc\u30de)";
    libiconv_t it = libiconv_open("UTF-8", "GBK");
    std::string s2;
    libiconv(it, reinterpret_cast<char **>(&s), reinterpret_cast<size_t *>(s.size()), reinterpret_cast<char **>(&s2),
          reinterpret_cast<size_t *>(s.size()));
    cout << s2;
//    std::filesystem::path p("./");
//    cout << p;
//    for (auto &entry: std::filesystem::recursive_directory_iterator(p)) {
//        cout << entry.path().filename()<<endl;
//    }
    return 0;
}
//int main() {
//    const char inFileName[] = "test3.flac";
//    const char outFileName[] = "test3.pcm";
//    FILE *file = fopen(outFileName, "w+b");
//    if (!file) {
//        printf("Cannot open output file.\n");
//        exit(1);
//    }
//
//    AVFormatContext *fmtCtx = avformat_alloc_context();
//    AVCodecContext *codecCtx = NULL;
//    AVPacket *pkt = av_packet_alloc();
//    AVFrame *frame = av_frame_alloc();
//
//    int aStreamIndex = -1;
//
//    if (avformat_open_input(&fmtCtx, inFileName, NULL, NULL) < 0) {
//        printf("Cannot open input file.\n");
//        return 1;
//    }
//    if (avformat_find_stream_info(fmtCtx, NULL) < 0) {
//        printf("Cannot find any stream in file.\n");
//        return 1;
//    }
//
//    av_dump_format(fmtCtx, 0, inFileName, 0);
//
//    AVDictionary *md = fmtCtx->metadata;
//    if (md) {
//        AVDictionaryEntry *tag = NULL;
//        while ((tag = av_dict_get(md, "", tag, AV_DICT_IGNORE_SUFFIX))) {
//            printf("%s: %s\n", tag->key, tag->value);
//        }
//    }
//    FILE *img = fopen("test.jpg", "wb");
//    if(fmtCtx->iformat->read_header(fmtCtx) < 0){
//        printf("Cannot read header.\n");
//        return 1;
//    }
//    for (int i = 0; i < fmtCtx->nb_streams; i++) {
//        if (fmtCtx->streams[i]->disposition & AV_DISPOSITION_ATTACHED_PIC) {
//            AVPacket pkt = fmtCtx->streams[i]->attached_pic;
//            fwrite(pkt.data, 1, pkt.size, img);
//        }
//    }
//    fclose(img);
//    for (size_t i = 0; i < fmtCtx->nb_streams; i++) {
//        if (fmtCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
//            aStreamIndex = (int) i;
//            break;
//        }
//    }
//    if (aStreamIndex == -1) {
//        printf("Cannot find audio stream.\n");
//        return 1;
//    }
//
//    AVCodecParameters *aCodecPara = fmtCtx->streams[aStreamIndex]->codecpar;
//    AVCodec *codec = avcodec_find_decoder(aCodecPara->codec_id);
//    if (!codec) {
//        printf("Cannot find any codec for audio.\n");
//        return 1;
//    }
//    codecCtx = avcodec_alloc_context3(codec);
//    if (avcodec_parameters_to_context(codecCtx, aCodecPara) < 0) {
//        printf("Cannot alloc codec context.\n");
//        return 1;
//    }
//    codecCtx->pkt_timebase = fmtCtx->streams[aStreamIndex]->time_base;
//
//    if (avcodec_open2(codecCtx, codec, NULL) < 0) {
//        printf("Cannot open audio codec.\n");
//        return 1;
//    }
//
//    uint64_t out_channel_layout = codecCtx->channel_layout;
//    enum AVSampleFormat out_sample_fmt = AV_SAMPLE_FMT_S16;
//    int out_sample_rate = 44100;
//    int out_channels = av_get_channel_layout_nb_channels(out_channel_layout);
//
//    uint8_t *audio_out_buffer = (uint8_t *) av_malloc(MAX_AUDIO_FRAME_SIZE * 2);
//
//    SwrContext *swr_ctx = swr_alloc_set_opts(NULL,
//                                             out_channel_layout,
//                                             out_sample_fmt,
//                                             codecCtx->sample_rate,
//                                             codecCtx->channel_layout,
//                                             codecCtx->sample_fmt,
//                                             codecCtx->sample_rate,
//                                             0, NULL);
//    swr_init(swr_ctx);
//
//    while (av_read_frame(fmtCtx, pkt) >= 0) {
//        if (pkt->stream_index == aStreamIndex) {
//            if (avcodec_send_packet(codecCtx, pkt) >= 0) {
//                while (avcodec_receive_frame(codecCtx, frame) >= 0) {
//
//                    int len = swr_convert(swr_ctx,
//                                          &audio_out_buffer,
//                                          MAX_AUDIO_FRAME_SIZE * 2,
//                                          (const uint8_t **) frame->data,
//                                          frame->nb_samples);
//                    if (len <= 0) {
//                        continue;
//                    }
//
//                    int dst_bufsize = av_samples_get_buffer_size(0,
//                                                                 out_channels,
//                                                                 len,
//                                                                 out_sample_fmt,
//                                                                 1);
//
//                    fwrite(audio_out_buffer, 1, dst_bufsize, file);
//                }
//            }
//        }
//        av_packet_unref(pkt);
//    }
//
//    av_frame_free(&frame);
//    av_packet_free(&pkt);
//    avcodec_close(codecCtx);
//    avcodec_free_context(&codecCtx);
//    avformat_free_context(fmtCtx);
//
//    fclose(file);
//
//    return 0;
//}

