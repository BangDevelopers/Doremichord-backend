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


#define MAX_AUDIO_FRAME_SIZE 384000

int main() {
    const char inFileName[] = "music.flac";
    const char outFileName[] = "test2.pcm";
    FILE *file = fopen(outFileName, "w+b");
    if (!file) {
        printf("Cannot open output file.\n");
        exit(1);
    }

    AVFormatContext *fmtCtx = avformat_alloc_context();
    AVCodecContext *codecCtx = NULL;
    AVPacket *pkt = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();

    int aStreamIndex = -1;

    if (avformat_open_input(&fmtCtx, inFileName, NULL, NULL) < 0) {
        printf("Cannot open input file.\n");
        return 1;
    }
    if (avformat_find_stream_info(fmtCtx, NULL) < 0) {
        printf("Cannot find any stream in file.\n");
        return 1;
    }

    av_dump_format(fmtCtx, 0, inFileName, 0);

    for (size_t i = 0; i < fmtCtx->nb_streams; i++) {
        if (fmtCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            aStreamIndex = (int) i;
            break;
        }
    }
    if (aStreamIndex == -1) {
        printf("Cannot find audio stream.\n");
        return 1;
    }

    AVCodecParameters *aCodecPara = fmtCtx->streams[aStreamIndex]->codecpar;
    AVCodec *codec = avcodec_find_decoder(aCodecPara->codec_id);
    if (!codec) {
        printf("Cannot find any codec for audio.\n");
        return 1;
    }
    codecCtx = avcodec_alloc_context3(codec);
    if (avcodec_parameters_to_context(codecCtx, aCodecPara) < 0) {
        printf("Cannot alloc codec context.\n");
        return 1;
    }
    codecCtx->pkt_timebase = fmtCtx->streams[aStreamIndex]->time_base;

    if (avcodec_open2(codecCtx, codec, NULL) < 0) {
        printf("Cannot open audio codec.\n");
        return 1;
    }

    uint64_t out_channel_layout = codecCtx->channel_layout;
    enum AVSampleFormat out_sample_fmt = AV_SAMPLE_FMT_S16;
    int out_sample_rate = 44100;
    int out_channels = av_get_channel_layout_nb_channels(out_channel_layout);

    uint8_t *audio_out_buffer = (uint8_t *) av_malloc(MAX_AUDIO_FRAME_SIZE * 2);

    SwrContext *swr_ctx = swr_alloc_set_opts(NULL,
                                             out_channel_layout,
                                             out_sample_fmt,
                                             96000,
                                             codecCtx->channel_layout,
                                             codecCtx->sample_fmt,
                                             codecCtx->sample_rate,
                                             0, NULL);
    swr_init(swr_ctx);

    while (av_read_frame(fmtCtx, pkt) >= 0) {
        if (pkt->stream_index == aStreamIndex) {
            if (avcodec_send_packet(codecCtx, pkt) >= 0) {
                while (avcodec_receive_frame(codecCtx, frame) >= 0) {

                    int len = swr_convert(swr_ctx,
                                          &audio_out_buffer,
                                          MAX_AUDIO_FRAME_SIZE * 2,
                                          (const uint8_t **) frame->data,
                                          frame->nb_samples);
                    if (len <= 0) {
                        continue;
                    }

                    int dst_bufsize = av_samples_get_buffer_size(0,
                                                                 out_channels,
                                                                 len,
                                                                 out_sample_fmt,
                                                                 1);

                    fwrite(audio_out_buffer, 1, dst_bufsize, file);
                }
            }
        }
        av_packet_unref(pkt);
    }

    av_frame_free(&frame);
    av_packet_free(&pkt);
    avcodec_close(codecCtx);
    avcodec_free_context(&codecCtx);
    avformat_free_context(fmtCtx);

    fclose(file);

    return 0;
}

