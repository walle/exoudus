#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "globals.h"

class cPlaystate : public cGamestate
{
    public:
            cPlaystate();
            ~cPlaystate();

            void run();
            void process_events( SDL_Event event);
            void manage_enemies();
            void manage_player();
            void draw_hud();
    private:
            cPlayer player;
            vector<cEnemy> enemies;
            cImage pause;
            cImage over;
            cImage quit;
            bool quitting;

            int lasttime;
            bool paused;
            bool gameover;
            Uint8* keys;
            SDL_Surface *lifebar;
            SDL_Rect liferect;
            cSprite explotion;
};

#endif
