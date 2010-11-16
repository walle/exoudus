#ifndef FRAME_H
#define FRAME_H

#include "globals.h"

class cFrame
{
    public:
        cFrame();
        cFrame( string file, int d );
        ~cFrame();

        void loadImg(string path);
        void setDelay(int d);
        int getImg() { return img; }
        int getDelay() { return delay; }
    private:
        int img;    // The element of the frame image in the image manager
        int delay;  // The number of milliseconds to delay after showing the animation
};

#endif
