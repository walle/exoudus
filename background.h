#ifndef BACKGROUND_H
#define BACKGROUND_H

class cBackground
{
    public:
            cBackground();
            ~cBackground();

            void draw_scroll();
    private:
            int scroll;
            SDL_Rect dest;
            SDL_Rect dest2;
            int img;
};

#endif
