#ifndef ANIMATION_H
#define ANIMATION_H

#include "globals.h"

class cAnimation
{
    public:
        cAnimation();
        cAnimation( vector<cFrame> f, string name );
        ~cAnimation();

        cFrame getFrame(int i);
        int getFrameImg(int i);
        int getFrameDelay(int i);
        int getFrameTime() { return frametime; }
        void addFrametime(int time);
        void setFrameTime(int time);
        string getName() { return name; }
        cFrame getCurrFrame() { return frames.at(currFrame); }
        int getCurrFrameImg(){ return frames.at(currFrame).getImg(); }
        int getCurrFrameDelay(){ return frames.at(currFrame).getDelay(); }
        void nextFrame();
        bool lastFrame();
        int getFrames() { return frames.size(); }
    private:
        vector<cFrame> frames;
        int frametime;
        int currFrame;
        string name;
};

#endif
