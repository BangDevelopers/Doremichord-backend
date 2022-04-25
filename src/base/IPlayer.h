//
// Created by Azusa on 2022/4/24.
//

#ifndef DOREMICHORD_BACKEND_IPLAYER_H

class IPlayer{
public:
    virtual void play()=0;

    virtual void pause()=0;

    virtual void stop()=0;

    virtual void jump_to(unsigned int time_sec)=0;

    virtual ~IPlayer()=0;
};

#define DOREMICHORD_BACKEND_IPLAYER_H

#endif //DOREMICHORD_BACKEND_IPLAYER_H
