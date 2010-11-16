#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "globals.h"

class cGamestate
{
    public:
            cGamestate() { }
            ~cGamestate() { }

            virtual void run() { /* Overloaded =) */  }
            virtual void process_events( SDL_Event event) {  /* Overloaded =) */  }
};

#endif
