#include "globals.h"

cOptionsstate::cOptionsstate()
{

}

cOptionsstate::~cOptionsstate()
{

}

void cOptionsstate::run()
{
    pBackground->draw_scroll();
    if(pSettings->showfps) { pFont->write(white, 10, 10, "FPS: %i", (int)framerate.fps()); }
	framerate.process();
    SDL_Flip(screen);
}

void cOptionsstate::process_events( SDL_Event event)
{
    while( SDL_PollEvent(&event) )
    {
        switch(event.type)
        {
            case SDL_QUIT:
                done = true;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        pGamestatemanager->set_state( pMenustate );
                        break;
                    case SDLK_F1:
                        Toggle_Fullscreen();
                        break;
                    case SDLK_LEFT:
                        pGamestatemanager->set_state( pMenustate );
                        break;
                    case SDLK_RIGHT:
                        pGamestatemanager->set_state( pPlaystate );
                        break;
                    case SDLK_UP:
                        pGamestatemanager->set_state( pOptionsstate );
                        break;
                    case SDLK_DOWN:

                        break;
                }
            default:
                break;
        }
    }
}
