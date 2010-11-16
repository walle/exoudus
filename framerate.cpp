#include "globals.h"

cFramerate::cFramerate()
{
    m_start==0;
    m_end=SDL_GetTicks();
    m_deltatime=0;
    m_fps=0;
    m_fpscounter=0;
}    

cFramerate::~cFramerate()
{
	
}    

void cFramerate::process()
{
    m_end=SDL_GetTicks();
    m_deltatime=m_end-m_start;  
    m_deltatime=m_deltatime/1000;
    m_start=m_end;
    
    m_current=SDL_GetTicks() * 0.001f;
    ++m_fpscounter;
    if(m_current-m_last > 1.0f) 
    { 
        m_last=m_current; 
        m_fps=m_fpscounter;
        m_fpscounter=0; 
    }
}

