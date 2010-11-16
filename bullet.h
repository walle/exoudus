#ifndef BULLET_H
#define BULLET_H

#include "globals.h"

class cBullet : public cSprite
{
    public:
            cBullet();
            ~cBullet();

            void move();

            bool visible;
};

#endif
