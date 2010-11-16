#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

class cPlayer : public cShip
{
    public:
            cPlayer();
            ~cPlayer();

    //private:
            int lives;
            int level;
            int score;
            int life;
};

#endif
