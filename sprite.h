#ifndef SPRITE_H
#define SPRITE_H

#include "globals.h"

// The sprite class
class cSprite
{
	public:
        cSprite();
        ~cSprite();

        // Self explained
        int getx() { return rect.x; }
        int gety() { return rect.y; }
        int getw() { return rect.w; }
        int geth() { return rect.h; }
        int getxcenter() { return rect.x + rect.w / 2; }
        int getycenter() { return rect.y + rect.h / 2; }
        SDL_Rect getRect() { return rect; }

        void setx(int x);
        void sety(int y);
        void setw(int w);
        void seth(int h);

        void setVisible(bool v);
        bool getVisible() { return visible; }

        void addx(int add);
        void addy(int add);

        void setColorkey(SDL_Color c);
        SDL_Color getColorkey() { return colorkey; }

        // Loads a sprite and all animations of it
        bool load(string path);

        // Draw the sprite to the selected surface
        void draw(SDL_Surface *dest);
        void draw(SDL_Surface *dest, int x, int y);
        void drawOnce(SDL_Surface *dest);
        void drawOnce(SDL_Surface *dest, int x, int y);

        // Check if the sprites overlap eachother..
        bool overlapping(cSprite *b);

        // Animation controls
        void pause();
        void resume();
        void reset();

        void setAnimation(string anim);

        int getFrame(string animation, int frame);

    private:
        SDL_Rect rect;
        SDL_Color colorkey;
        vector<cAnimation> animations;
        int alpha;
        int currAnim;
        bool paused;
        bool visible;
};


#endif
