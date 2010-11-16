#include "globals.h"

cShip::cShip()
{
    bullets.resize(20);
}

cShip::~cShip()
{

}

void cShip::draw( SDL_Surface *dest )
{
    sprite.draw(dest);
}

void cShip::move( int nx, int ny )
{
    sprite.addx(nx);
    sprite.addy(ny);
}

void cShip::shoot()
{
    pSoundManager->playsound("data/sound/shoot.wav", 0);
    for( int i = 0; i < bullets.size(); i++ )
    {
        if(bullets.at(i).visible == false)
        {
            bullets.at(i).setx( sprite.getx() + sprite.getw() - 30 );
            bullets.at(i).sety( sprite.getycenter() - bullets.at(i).geth()  / 2 );
            bullets.at(i).visible = true;
             break;
        }
    }
}

void cShip::update()
{
    for( int i = 0; i < bullets.size(); i++ )
    {
        if(bullets.at(i).visible == true)
        {
            bullets.at(i).move();
            bullets.at(i).draw( screen );
            if(bullets.at(i).getx() > screen->w ) { bullets.at(i).visible = false; }
        }
    }
}

