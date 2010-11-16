#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "globals.h"

class cMenustate : public cGamestate
{
    public:
            cMenustate();
            ~cMenustate();

            void run();
            void process_events( SDL_Event event);
    private:
           cSprite playitem;
           cSprite optionsitem;
           cSprite quititem;
           cSprite title;
           cSprite mouse;
};

#endif
