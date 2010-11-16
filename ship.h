#ifndef SHIP_H
#define SHIP_H

#include "globals.h"

class cShip
{
    public:
            cShip();
            ~cShip();

            void draw( SDL_Surface *dest );
            void move(int nx, int ny);
            void shoot();
            void update();

    //private:
            cSprite sprite;
            vector<cBullet> bullets;
};

#endif
