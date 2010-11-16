#ifndef IMAGE_H
#define IMAGE_H

#include "globals.h"

// The image class
class cImage
{
	public:
        cImage();
        ~cImage();

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
        void setAlpha(int a);
        SDL_Color getColorkey() { return colorkey; }

        // Loads a image
        bool load(string path);

        // Draw the sprite to the selected surface
        void draw(SDL_Surface *dest);
        void draw(SDL_Surface *dest, int x, int y);

        // Check if the image overlap eachother..
        bool overlapping(cImage *b);

    private:
        SDL_Rect rect;
        SDL_Color colorkey;
        int img;
        int alpha;
        bool visible;
};


#endif
