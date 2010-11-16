#ifndef OPTIONSSTATE_H
#define OPTIONSSTATE_H

#include "globals.h"

class cOptionsstate : public cGamestate
{
    public:
            cOptionsstate();
            ~cOptionsstate();

            void run();
            void process_events( SDL_Event event);
    private:

};

#endif
