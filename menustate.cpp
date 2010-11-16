#include "globals.h"

cMenustate::cMenustate()
{
    playitem.load("data/menu/play");
    playitem.setx(screen->w / 2 - playitem.getw() / 2 );
    playitem.sety(screen->h / 2 - playitem.geth() );

    optionsitem.load("data/menu/options");
    optionsitem.setx(screen->w / 2 - optionsitem.getw() / 2 );
    optionsitem.sety(screen->h / 2  );

    quititem.load("data/menu/quit");
    quititem.setx(screen->w / 2 - quititem.getw() / 2 );
    quititem.sety(screen->h / 2 + quititem.geth() );

    title.load("data/menu/title");
    title.setx(screen->w / 2 - title.getw() / 2 );
    title.sety( title.geth() / 2 );

    mouse.load("data/menu/mouse");
}

cMenustate::~cMenustate()
{

}

void cMenustate::run()
{
    SDL_ShowCursor(0);
    pBackground->draw_scroll();
    playitem.draw(screen);
    optionsitem.draw(screen);
    quititem.draw(screen);
    title.draw( screen );

    mouse.draw( screen );

    if(pSettings->showfps) { pFont->write(white, 10, 10, "FPS: %i", (int)framerate.fps()); }
	framerate.process();
    SDL_Flip(screen);
}

void cMenustate::process_events( SDL_Event event)
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
                    case SDLK_F1:
                        Toggle_Fullscreen();
                        break;
                    case SDLK_LEFT:
                        break;
                    case SDLK_RIGHT:
                        break;
                    case SDLK_UP:
                        break;
                    case SDLK_DOWN:

                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(pixel_collision( &playitem, mouse.getx(), mouse.gety() ) & event.button.button == SDL_BUTTON_LEFT)
                {
                    pGamestatemanager->set_state(pPlaystate);
                    pSoundManager->resumemusic();
                }

                if(pixel_collision( &optionsitem, mouse.getx(), mouse.gety() ) & event.button.button == SDL_BUTTON_LEFT)
                {
                    pGamestatemanager->set_state(pOptionsstate);
                }

                if(pixel_collision( &quititem, mouse.getx(), mouse.gety() ) & event.button.button == SDL_BUTTON_LEFT)
                {
                    done = true;
                }
                break;
            case SDL_MOUSEMOTION:
                mouse.setx( event.motion.x);
                mouse.sety( event.motion.y );

                if(pixel_collision( &playitem, mouse.getx(), mouse.gety() ) )
                {
                   playitem.setAnimation("hover");
                }
                else { playitem.setAnimation("normal"); }
                if(pixel_collision( &optionsitem, mouse.getx(), mouse.gety() ) )
                {
                   optionsitem.setAnimation("hover");
                }
                else { optionsitem.setAnimation("normal"); }
                if(pixel_collision( &quititem, mouse.getx(), mouse.gety() ) )
                {
                    quititem.setAnimation("hover");
                }
                else { quititem.setAnimation("normal"); }
                break;
            default:
                break;
        }
    }
}

