#include "globals.h"

cPlayer::cPlayer()
{
    lives = 3;
    level = 1;
    score = 0;
    life = 10;
    sprite.load("data/sprites/player");
    sprite.setx(10);
    sprite.sety(screen->h / 2 - sprite.geth() / 2);
}

cPlayer::~cPlayer()
{

}


