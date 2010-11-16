#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "globals.h"

class cGamestatemanager
{
    public:
            cGamestatemanager();
            cGamestatemanager( cGamestate *nstate);
            ~cGamestatemanager();

            void run();
            void process_events( SDL_Event event);
            void set_state( cGamestate *nstate );

    private:
            cGamestate *pGamestate;
};

#endif
