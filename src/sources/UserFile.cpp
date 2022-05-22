//
// Created by RCGss on 2022/5/12.
//

#include "UserFile.h"
#include <fstream>
#include <string>
#include "FileCryption.h"
#include <filesystem>


bool UserFile::user_login(std::string username,std::string password) {
    std::string filepath="./users/"+username+"/password.dmc";
    std::ifstream file(filepath, std::ios::in| std::ios::binary);

    if (!file.is_open()){
        return false;
    }
    std::string fileInfo;
    file.read((char *)&fileInfo, sizeof(std::string));
    FileCryption ur;
    std::string fileInfo_dc=ur.decrypt(username,fileInfo);
    if(fileInfo_dc==password){
        file.close();
        return true;
    }
    else{
        file.close();
        return false;
    }

}

bool UserFile::user_register(std::string username,std::string password) {
    std::filesystem::path root("./");
    std::string filepath="users/"+username;
    std::filesystem::path users_path=root / filepath;
    if(!std::filesystem::exists(users_path)){
        std::filesystem::create_directory(users_path);
        filepath="./users/"+username+"/password.dmc";
        std::fstream file(filepath, std::ios::in| std::ios::out|std::ios::binary);
        if (!file.is_open()){
            return false;
        }
        FileCryption ur;
        std::string psw_ec=ur.encrypt(username,password);
        file.write((char *)&psw_ec, sizeof(std::string));
        file.close();
        return true;
    }
    else{
        return false;
    }




}

bool UserFile::user_fgpassword(std::string username,std::string password,std::string password_new){


    std::string filepath="./users/"+username+"/password.dmc";
    std::ifstream file(filepath, std::ios::in| std::ios::binary);
    if (!file.is_open()){
        return false;
    }
    std::string fileInfo;
    file.read((char *)&fileInfo, sizeof(std::string));
    FileCryption ur;
    std::string fileInfo_dc=ur.decrypt(username,fileInfo);
    if(fileInfo_dc==password){
        std::string psw_ec=ur.encrypt(username,password_new);

        file.close();
        std::ofstream file(filepath, std::ios::out|std::ios::trunc| std::ios::binary);
        file.write((char *)&psw_ec, sizeof(std::string));
        file.close();
        return true;
    }
    else{
        file.close();
        return false;
    }
}
