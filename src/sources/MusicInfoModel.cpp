//
// Created by Azusa on 2022/5/6.
//
#include "MusicInfoModel.h"

MusicInfoModel::MusicInfoModel() = default;


std::string MusicInfoModel::serialization() {
    Json::Value root;
    root["artist"] = artist;
    root["title"] = title;
    root["album"] = album;
    root["composer"] = composer;
    root["path"] = path;
    root["cover_path"] = cover_path;
    root["sample_rate"] = sample_rate;
    root["bit_rate"] = bit_rate;
    root["length"] = length;
    return root.toStyledString();
}

bool MusicInfoModel::construction(const std::string serialized_text) {
    Json::Value root;
    Json::Reader reader;
    if (!reader.parse(serialized_text, root)) {
        return false;
    }
    artist = root["artist"].asString();
    title = root["title"].asString();
    album = root["album"].asString();
    composer = root["composer"].asString();
    path = root["path"].asString();
    cover_path = root["cover_path"].asString();
    sample_rate = root["sample_rate"].asInt();
    bit_rate = root["bit_rate"].asInt();
    length = root["length"].asInt();
    return true;
}

const std::string &MusicInfoModel::getArtist() const {
    return artist;
}

const std::string &MusicInfoModel::getTitle() const {
    return title;
}

const std::string &MusicInfoModel::getAlbum() const {
    return album;
}

const std::string &MusicInfoModel::getComposer() const {
    return composer;
}

const std::string &MusicInfoModel::getPath() const {
    return path;
}

const std::string &MusicInfoModel::getCoverPath() const {
    return cover_path;
}

int MusicInfoModel::getSampleRate() const {
    return sample_rate;
}

int MusicInfoModel::getBitRate() const {
    return bit_rate;
}

int MusicInfoModel::getLength() const {
    return length;
}

void MusicInfoModel::setArtist(const std::string &artist) {
    MusicInfoModel::artist = artist;
}

void MusicInfoModel::setTitle(const std::string &title) {
    MusicInfoModel::title = title;
}

void MusicInfoModel::setAlbum(const std::string &album) {
    MusicInfoModel::album = album;
}

void MusicInfoModel::setComposer(const std::string &composer) {
    MusicInfoModel::composer = composer;
}

void MusicInfoModel::setPath(const std::string &path) {
    MusicInfoModel::path = path;
}

void MusicInfoModel::setCoverPath(const std::string &coverPath) {
    cover_path = coverPath;
}

void MusicInfoModel::setSampleRate(int sampleRate) {
    sample_rate = sampleRate;
}

void MusicInfoModel::setBitRate(int bitRate) {
    bit_rate = bitRate;
}

void MusicInfoModel::setLength(int length) {
    MusicInfoModel::length = length;
}

MusicInfoModel::~MusicInfoModel() = default;
