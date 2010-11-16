#include "globals.h"

cPlaystate::cPlaystate()
{
    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
    lasttime = 0;
    paused = false;
    gameover = false;
    quitting = false;
    enemies.resize(20);
    for( int i = 0; i < enemies.size(); i++)
    {
        enemies.at(i).life = 1 + ( ( rand() ) * ( 5 - 1 ) / RAND_MAX );
        enemies.at(i).speed = 200 + ( ( rand() ) * ( 500 - 200 ) / RAND_MAX );
    }
    lifebar = SDL_CreateRGBSurface(0, 400, 40, 32, 0, 0, 0, 0);
    SDL_SetAlpha(lifebar, SDL_SRCALPHA, 128);
    liferect.x = 700;
    liferect.y = 10;
    pause.load("data/menu/paused/1.png");
    pause.setx(screen->w / 2 - pause.getw() / 2 );
    pause.sety(screen->h / 2 - pause.geth() * 2 );
    over.load("data/menu/gameover/1.png");
    over.setAlpha(128);
    quit.load("data/menu/quitting/1.png");
    quit.setAlpha(128);
    explotion.load("data/sprites/explotion");
    explotion.setVisible(false);
}

cPlaystate::~cPlaystate()
{
    SDL_FreeSurface(lifebar);
}

void cPlaystate::run()
{
    if(paused == false)
    {
        pBackground->draw_scroll();
        if(gameover == false && quitting == false)
        {
            manage_enemies();
            manage_player();
            draw_hud();
        }
    }
    if(paused == true) { pause.draw( screen ); }
    if(gameover == true) { over.draw( screen ); }
    if(quitting == true) { quit.draw(screen); }
    explotion.drawOnce(screen);
    framerate.process();
    SDL_Flip(screen);
}

void cPlaystate::process_events( SDL_Event event)
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
                        quitting = true;
                        break;
                    case SDLK_F1:
                        //Toggle_Fullscreen();
                        break;
                    case SDLK_SPACE:
                        player.shoot();
                        break;
                    case SDLK_RETURN:
                        paused = true;
                        break;
                    case SDLK_p:
                        if(paused == true) { paused = false; }
                        else { paused = true; }
                        break;
                    case SDLK_y:
                        if(gameover == true)
                        {
                            gameover = false;
                            player.lives = 3;
                            player.life = 10;
                            player.score = 0;
                            player.sprite.setx(10);
                            player.sprite.sety(screen->h / 2 - player.sprite.geth() / 2);
                            for(int i = 0; i < player.bullets.size(); i++)
                            {
                                player.bullets.at(i).visible = false;
                            }
                            for(int i = 0; i < enemies.size(); i++)
                            {
                                enemies.at(i).visible = false;
                            }
                            SDL_Delay(200);
                        }
                        if(quitting == true)
                        {
                            quitting = false;
                            pSoundManager->pausemusic();
                            pGamestatemanager->set_state( pMenustate );
                        }
                        break;
                    case SDLK_n:
                        if(gameover == true)
                        {
                            gameover = false;
                            player.lives = 3;
                            player.life = 10;
                            player.score = 0;
                            player.sprite.setx(10);
                            player.sprite.sety(screen->h / 2 - player.sprite.geth() / 2);
                            for(int i = 0; i < player.bullets.size(); i++)
                            {
                                player.bullets.at(i).visible = false;
                            }
                            for(int i = 0; i < enemies.size(); i++)
                            {
                                enemies.at(i).visible = false;
                            }
                            pGamestatemanager->set_state(pMenustate);
                        }
                        if(quitting == true)
                        {
                            quitting = false;
                        }
                        break;
                }
            default:
                break;
        }
    }

    if( paused == false && quitting == false)
    {

        keys = SDL_GetKeyState(NULL);

        if(keys[SDLK_UP])
        {
            player.move(0, -350 * framerate.dtime());
        }

        if(keys[SDLK_DOWN])
        {
            if(player.sprite.gety() + player.sprite.geth() < screen->h ) { player.move(0, 350 * framerate.dtime()); }
        }

        if(keys[SDLK_LEFT])
        {
            player.move(-350 * framerate.dtime(), 0);
        }

        if(keys[SDLK_RIGHT])
        {
            if(player.sprite.getx() + player.sprite.getw() < screen->w ) { player.move(350 * framerate.dtime(), 0); }
        }
    }

}

void cPlaystate::manage_enemies()
{
    if( SDL_GetTicks() - lasttime > 500 )
    {
        for(int i = 0; i < enemies.size(); i++)
        {
            if(enemies.at(i).visible == false)
            {
                enemies.at(i).sprite.setx( screen->w + 10 );
                enemies.at(i).sprite.sety( 0 + ( ( rand() ) * ( screen->h -enemies.at(i).sprite.geth() - 0 ) / RAND_MAX ) );
                enemies.at(i).visible = true;
                enemies.at(i).life = 1 + ( ( rand() ) * ( 5 - 1 ) / RAND_MAX );
                break;
            }
        }

        lasttime = SDL_GetTicks();
    }

    for( int i = 0; i < enemies.size(); i++ )
    {
        if(enemies.at(i).visible == true)
        {
            enemies.at(i).move( -enemies.at(i).speed * framerate.dtime(), 0 );
            enemies.at(i).draw( screen );
            if(enemies.at(i).sprite.getx() <= 0 )
            {
                enemies.at(i).visible = false;
                player.score -= 100 + ( ( rand() ) * ( 300 - 100 ) / RAND_MAX );
            }
            if(player.sprite.overlapping( &enemies.at(i).sprite) )
            {
                explotion.setVisible(true);
                explotion.setx( enemies.at(i).sprite.getxcenter() - explotion.getw() / 2 );
                explotion.sety( enemies.at(i).sprite.getycenter() - explotion.geth() / 2 );
                enemies.at(i).visible = false;
                player.life -= 2;
            }
        }
    }

    for(int i = 0; i < player.bullets.size(); i++)
    {
        for(int j = 0; j < enemies.size(); j++)
        {
            if( enemies.at(j).visible == true & player.bullets.at(i).visible == true )
            {
                if(player.bullets.at(i).overlapping( &enemies.at(j).sprite ) )
                {
                    player.bullets.at(i).visible = false;
                    enemies.at(j).hits++;
                    player.score += 30 + ( ( rand() ) * ( 90 - 30 ) / RAND_MAX );
                    if(enemies.at(j).hits >= enemies.at(j).life )
                    {
                        enemies.at(j).visible = false;
                        player.score += 100 + ( ( rand() ) * ( 600 - 100 ) / RAND_MAX );
                    }
                }
            }
        }
    }
}

void cPlaystate::manage_player()
{
    player.update();
    player.draw( screen );
    if(player.life <= 0)
    {
        player.lives--;
        player.sprite.setx(10);
        player.sprite.sety(screen->h / 2 - player.sprite.geth() / 2);
        player.life = 10;
    }

    if(player.lives <= 0)
    {
        gameover = true;
    }
}

void cPlaystate::draw_hud()
{
    if(pSettings->showfps) { pFont->write(white, 10, 10, "FPS: %i", (int)framerate.fps()); }
    pFont->write(white, liferect.x + lifebar->w + 10, liferect.y, "Score: %i", player.score);
    pFont->write(white, liferect.x + lifebar->w + 10, liferect.y + pFont->height() + 1, "Lives: %i", player.lives);

    SDL_Rect life;
    SDL_FillRect(lifebar, NULL, 0x00);

    life.x = 1;
    life.y = 1;
    life.w = (lifebar->w / 10) * player.life;
    life.h = lifebar->h - 2;

    SDL_FillRect(lifebar, &life, 0x00ff00);

    SDL_BlitSurface(lifebar, NULL, screen, &liferect);
}


