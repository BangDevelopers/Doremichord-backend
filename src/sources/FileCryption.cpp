#include "FileCryption.h"

//
// Created by RCGss on 2022/5/22.
//

#include "FileCryption.h"

string FileCryption::encrypt(string account, string data) {
    string str,ep=data;
    for (char ch = '~'; ch >= ' '; ch--) {
        str.push_back(ch);
    }

    account += str;

    string key1;
    for (int i = 0; i < account.size(); i++) {

        if (key1.find(account[i]) == key1.npos)
            key1.push_back(account[i]);
    }

    for (int i = 0; i < data.size(); i++) {
        ep[i] = key1[data[i]-32];
    }
    return ep;

}

string FileCryption::decrypt(string account, string data) {
    string str, dp = data;
    for (char ch = '~'; ch >= ' '; ch--) {
        str.push_back(ch);
    }

    account += str;
    string key1;
    for (int i = 0; i < account.size(); i++) {

        if (key1.find(account[i]) == key1.npos)
            key1.push_back(account[i]);
    }

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < key1.size(); j++) {
            if (data[i] == key1[j]) {
                dp[i] = char(j + 32);
            }
        }
    }
    return dp;

}