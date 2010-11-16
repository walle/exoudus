#ifndef FONT_H
#define FONT_H

#include "globals.h"

class cFont
{
    public:
        cFont();
        ~cFont();

        bool init(std::string file, int size);

        void write(SDL_Color color, int x, int y, const char *msg, ...);

        int height() { return TTF_FontHeight( font ); }

    private:
        TTF_Font *font;
        SDL_Surface *img;
};


#endif
