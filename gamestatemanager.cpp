#include "globals.h"

cGamestatemanager::cGamestatemanager()
{
    pGamestate = NULL;
}

cGamestatemanager::cGamestatemanager( cGamestate *nstate )
{
    pGamestate = nstate;
}

cGamestatemanager::~cGamestatemanager()
{
    if( pGamestate )
    {
        delete pGamestate;
        pGamestate = NULL;
    }
}

void cGamestatemanager::run()
{
    pGamestate->run();
}

void cGamestatemanager::process_events( SDL_Event event )
{
    pGamestate->process_events( event );
}

void cGamestatemanager::set_state( cGamestate *nstate )
{
    //delete pGamestate;
    pGamestate = nstate;
}

