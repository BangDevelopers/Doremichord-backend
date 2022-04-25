//
// Created by Azusa on 2022/4/25.
//

#ifndef DOREMICHORD_BACKEND_SUBJECT_H
#define DOREMICHORD_BACKEND_SUBJECT_H

#include "Observer.h"
#include <vector>

class Subject {
protected:
    std::vector<Observer *> observers;
public:
    virtual ~Subject() = default;
    virtual void attach(Observer *observer) = 0;
    virtual void detach(Observer *observer) = 0;
    virtual void notify() = 0;
};
#endif //DOREMICHORD_BACKEND_SUBJECT_H
