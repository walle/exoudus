#include "globals.h"

cImage::cImage()
{
	visible = true;
	rect.x = 0;
	rect.y = 0;
	alpha = 0;
}

cImage::~cImage()
{

}

void cImage::setx(int x)
{
	rect.x = x;
}

void cImage::sety(int y)
{
	rect.y = y;
}

void cImage::setw(int w)
{
	rect.w = w;
}

void cImage::seth(int h)
{
	rect.h = h;
}

void cImage::setVisible(bool v)
{
    visible = v;
}

void cImage::addx(int add)
{
	rect.x += add;
}

void cImage::addy(int add)
{
	rect.y += add;
}

void cImage::setColorkey(SDL_Color c)
{
    colorkey = c;
    SDL_SetColorKey(pImgManager->get(img), SDL_SRCCOLORKEY,SDL_MapRGB(pImgManager->get(img)->format, colorkey.r, colorkey.g, colorkey.b));
}

void cImage::setAlpha(int a)
{
    alpha = a;
    SDL_SetAlpha(pImgManager->get(img), SDL_SRCALPHA, alpha);
}

bool cImage::load(string path)
{
    img = pImgManager->add( path );

    rect.w = pImgManager->get(img)->w;
    rect.h = pImgManager->get(img)->h;

return true;
}

void cImage::draw(SDL_Surface *dest)
{
    if(visible)
    {
        SDL_BlitSurface(pImgManager->get(img), NULL, dest, &rect);
    }
}

void cImage::draw(SDL_Surface *dest, int x, int y)
{

    if(visible)
    {

        rect.x = x;
        rect.y = y;

        SDL_BlitSurface(pImgManager->get(img), NULL, dest, &rect);
    }

}

// Checking ovelapping...not the edges, therefor the -1
bool cImage::overlapping(cImage *b)
{
    if ( rect.y + rect.h - 1 < b->gety() ) { return false; }
    if ( rect.y > b->gety() + b->geth() - 1 ) { return false; }
    if ( rect.x + rect.w - 1 < b->getx() ) { return false; }
    if ( rect.x > b->getx() + b->getw() -1 ) { return false; }

return true;
}






