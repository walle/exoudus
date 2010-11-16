#include "globals.h"

cBullet::cBullet()
{
    load("data/sprites/bullet");
    visible = false;
}

cBullet::~cBullet()
{

}

void cBullet::move()
{
    addx( framerate.dtime() * 500 );
}

