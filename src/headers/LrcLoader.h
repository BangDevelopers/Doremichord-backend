//
// Created by Azusa on 2022/5/2.
//

#ifndef DOREMICHORD_BACKEND_LRCLOADER_H
#define DOREMICHORD_BACKEND_LRCLOADER_H

#include "LrcModel.h"

class LrcLoader {
public:
    static LrcModel load(const char *path);
};

#endif //DOREMICHORD_BACKEND_LRCLOADER_H
