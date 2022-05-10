//
// Created by Azusa on 2022/4/25.
//

#ifndef DOREMICHORD_BACKEND_MUSICINFOMODEL_H
#define DOREMICHORD_BACKEND_MUSICINFOMODEL_H

#include <string>
#include "json.h"
#include "base/BaseModel.h"




class MusicInfoModel :public BaseModel{
protected:
    std::string artist;
    std::string title;
    std::string album;
    std::string composer;
    std::string path;
    std::string cover_path;
    int sample_rate{0};
    int bit_rate{0};
    int length{0};
public:
    MusicInfoModel();

    const std::string &getArtist() const;

    const std::string &getTitle() const;

    const std::string &getAlbum() const;

    const std::string &getComposer() const;

    const std::string &getPath() const;

    const std::string &getCoverPath() const;

    int getSampleRate() const;

    int getBitRate() const;

    int getLength() const;

    void setArtist(const std::string &artist);

    void setTitle(const std::string &title);

    void setAlbum(const std::string &album);

    void setComposer(const std::string &composer);

    void setPath(const std::string &path);

    void setCoverPath(const std::string &coverPath);

    void setSampleRate(int sampleRate);

    void setBitRate(int bitRate);

    void setLength(int length);

    friend class MusicInfoLoader;

    std::string serialization() override;

    bool construction(std::string serialized_text) override;

    ~MusicInfoModel();

};

#endif //DOREMICHORD_BACKEND_MUSICINFOMODEL_H
