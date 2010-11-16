#include "globals.h"

cFrame::cFrame()
{
    img = 0;
    delay = 0;
}

cFrame::cFrame( string file, int d)
{
    img = pImgManager->add(file);
    delay = d;
}

cFrame::~cFrame()
{

}

void cFrame::loadImg(string path)
{
    img = pImgManager->add(path);
}

void cFrame::setDelay(int d)
{
    delay = d;
}
