//
// Created by RCGss on 2022/5/22.
//

#ifndef DOREMICHORD_BACKEND_FILECRYPTION_H
#define DOREMICHORD_BACKEND_FILECRYPTION_H

#include <iostream>
#include <string>
using namespace std;
class FileCryption {
public:
    string encrypt(string account, string data);
    string decrypt(string account, string data);

};

#endif //DOREMICHORD_BACKEND_FILECRYPTION_H
