#ifndef FRAMERATE_H
#define FRAMERATE_H

#include "globals.h"

class cFramerate
{
    public:
        cFramerate();
        ~cFramerate();
        
        void process();
        float dtime() { return m_deltatime; }
        float fps() { return m_fps; }
    private:
        float m_deltatime;
        float m_start;
        float m_end;
        
        float m_fps;
        float m_fpscounter;
        float m_last;
        float m_current;
};    

#endif
