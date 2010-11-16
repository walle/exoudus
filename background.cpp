#include "globals.h"

cBackground::cBackground()
{
    scroll = 0;
    img = pImgManager->add("data/sprites/background/1.png");
}

cBackground::~cBackground()
{

}

void cBackground::draw_scroll()
{
    // We first check, if the background has scrolled more than it's own
    // width. And if so, then we must draw 2 images on the screen:
    // the end of one scrolling background and the start of another.
    if( scroll > pImgManager->get(img)->w - screen->w )
    {
        dest.x = 0;
        dest.y = 0;

        dest2.x = scroll;
        dest2.y = 0;
        dest2.w = pImgManager->get(img)->w - scroll;
        dest2.h = screen->h;

        SDL_BlitSurface(pImgManager->get(img), &dest2, screen, &dest);

        dest.x = pImgManager->get(img)->w - scroll - 1;
        dest.y = 0;

        dest2.x = 0;
        dest2.y = 0;
        dest2.w = screen->w - (pImgManager->get(img)->w - scroll);
        dest2.h = screen->h;

         SDL_BlitSurface(pImgManager->get( img ), &dest2, screen, &dest);

        // If not then we draw only one background
    }
    else
    {
        dest.x = 0;
        dest.y = 0;

        dest2.x = scroll;
        dest2.y = 0;
        dest2.w = screen->w;
        dest2.h = screen->h;

        SDL_BlitSurface(pImgManager->get( img ), &dest2, screen, &dest);
    }

    scroll += framerate.dtime() * 100;
    if(scroll >= pImgManager->get(img)->w ) { scroll = 0; }
}