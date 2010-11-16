#include "globals.h"

cAnimation::cAnimation()
{
    frames.clear();
    frametime = 0;
    currFrame = 0;
    name = "";
}

cAnimation::cAnimation( vector<cFrame> f, string n)
{
    frames = f;
    frametime = 0;
    currFrame = 0;
    name = n;
}

cAnimation::~cAnimation()
{
    frames.clear();
}

cFrame cAnimation::getFrame(int i)
{
    if(i < frames.size())
    {
        return frames.at(i);
    }
}

int cAnimation::getFrameImg(int i)
{
    if(i < frames.size())
    {
        return frames.at(i).getImg();
    }
}

int cAnimation::getFrameDelay(int i)
{
    if(i < frames.size())
    {
        return frames.at(i).getDelay();
    }
}

void cAnimation::addFrametime(int time)
{
    frametime += time;
}

void cAnimation::setFrameTime(int time)
{
    frametime = time;
}

void cAnimation::nextFrame()
{
    if(currFrame == frames.size() - 1) { currFrame = 0; }
    else { currFrame++; }
}

bool cAnimation::lastFrame()
{
    if(currFrame == 0) { return true; }

    return false;
}

