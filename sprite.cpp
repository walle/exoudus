#include "globals.h"

cSprite::cSprite()
{
	animations.clear();
	paused = false;
	currAnim = 0;
	visible = true;
	rect.x = 0;
	rect.y = 0;
	alpha = 0;
}

cSprite::~cSprite()
{
	animations.clear();
}

void cSprite::setx(int x)
{
	rect.x = x;
}

void cSprite::sety(int y)
{
	rect.y = y;
}

void cSprite::setw(int w)
{
	rect.w = w;
}

void cSprite::seth(int h)
{
	rect.h = h;
}

void cSprite::setVisible(bool v)
{
    visible = v;
}

void cSprite::addx(int add)
{
	rect.x += add;
}

void cSprite::addy(int add)
{
	rect.y += add;
}

void cSprite::setColorkey(SDL_Color c)
{
    colorkey = c;
    //SDL_SetColorKey(pImgManager->get(img), SDL_SRCCOLORKEY,SDL_MapRGB(pImgManager->get(img)->format, colorkey.r, colorkey.g, colorkey.b));
}

bool cSprite::load(string path)
{
    string xml = path + "/sprite.xml";
	TiXmlDocument *File = new TiXmlDocument(xml);
        if(File->LoadFile())
        {
            TiXmlElement* type = File->FirstChildElement("sprite");
            TiXmlElement* data = type->FirstChildElement("animation");

            colorkey.r = string_to_int(type->Attribute("red"));
            colorkey.g = string_to_int(type->Attribute("green"));
            colorkey.b = string_to_int(type->Attribute("blue"));
            alpha =  string_to_int(type->Attribute("alpha"));

            while(data)
            {
              std::vector<cFrame> Frames;
              TiXmlElement* animation = data->FirstChildElement("frame");
              while(animation)
              {
                    string f = path + "/" + (string)animation->Attribute("file");
                    cFrame temp( f, string_to_int((string)animation->Attribute("delay")));
                    SDL_SetColorKey(pImgManager->get(temp.getImg()), SDL_SRCCOLORKEY,SDL_MapRGB(pImgManager->get(temp.getImg())->format, colorkey.r, colorkey.g, colorkey.b));
                    SDL_SetAlpha(pImgManager->get(temp.getImg()), SDL_SRCALPHA, alpha);
                    Frames.push_back(temp);
                    animation = animation->NextSiblingElement("frame");
              }
              cAnimation temp(Frames, (string)data->Attribute("name"));
              animations.push_back( temp );
              Frames.clear();
              data = data->NextSiblingElement("animation");
            }
            File->Clear();
        }
        else
        {
            delete File;
            pLog->write("Couldn't load file: %s", path.c_str() );
            return false;
        }

delete File;

rect.w = pImgManager->get(animations.at(0).getFrameImg(0))->w;
rect.h = pImgManager->get(animations.at(0).getFrameImg(0))->h;

return true;
}

void cSprite::draw(SDL_Surface *dest)
{
    if(visible)
    {
        if(animations.at(currAnim).getFrames() > 1)
        {
            if(paused == false)
            {
                if(animations.at(currAnim).getFrameTime() + animations.at(currAnim).getCurrFrameDelay() <= SDL_GetTicks() )
                {
                    animations.at(currAnim).nextFrame();
                    animations.at(currAnim).setFrameTime( SDL_GetTicks() );
                }
            }
        }

        SDL_BlitSurface(pImgManager->get(animations.at(currAnim).getCurrFrameImg()), NULL, dest, &rect);
    }
}

void cSprite::draw(SDL_Surface *dest, int x, int y)
{
	/*if(paused == false)
    {
        if(lastframe + animation.at(currframe).delay <= SDL_GetTicks())
        {
            if(currframe == animation.size()-1)
            {
                currframe = 0;
            }
            else
            {
            	currframe++;
            }
            lastframe=SDL_GetTicks();
        }
    }
    SDL_BlitSurface(pImgManager->get(animation.at(currframe).img), NULL, dest, &rect);

    rect.x = x;
    rect.y = y;

    //relative.x = rect.x - pCamera->x;
    //relative.y = rect.y - pCamera->y;

    SDL_BlitSurface(pImgManager->get(img), NULL, dest, &relative);*/

    if(visible)
    {
        if(animations.at(currAnim).getFrames() > 1)
        {
            if(paused == false)
            {
                if(animations.at(currAnim).getFrameTime() + animations.at(currAnim).getCurrFrameDelay() <= SDL_GetTicks() )
                {
                    animations.at(currAnim).nextFrame();
                    animations.at(currAnim).setFrameTime( SDL_GetTicks() );
                }
            }
        }

        rect.x = x;
        rect.y = y;

        SDL_BlitSurface(pImgManager->get(animations.at(currAnim).getCurrFrameImg()), NULL, dest, &rect);
    }

}

void cSprite::drawOnce(SDL_Surface *dest)
{
    if(visible)
    {
        if(animations.at(currAnim).getFrames() > 1)
        {
            if(paused == false)
            {
                if(animations.at(currAnim).getFrameTime() + animations.at(currAnim).getCurrFrameDelay() <= SDL_GetTicks() )
                {
                    animations.at(currAnim).nextFrame();
                    animations.at(currAnim).setFrameTime( SDL_GetTicks() );
                    if(animations.at(currAnim).lastFrame()) { visible = false; }
                }
            }
        }

        SDL_BlitSurface(pImgManager->get(animations.at(currAnim).getCurrFrameImg()), NULL, dest, &rect);
    }
}

void cSprite::drawOnce(SDL_Surface *dest, int x, int y)
{
    if(visible)
    {
        if(animations.at(currAnim).getFrames() > 1)
        {
            if(paused == false)
            {
                if(animations.at(currAnim).getFrameTime() + animations.at(currAnim).getCurrFrameDelay() <= SDL_GetTicks() )
                {
                    animations.at(currAnim).nextFrame();
                    animations.at(currAnim).setFrameTime( SDL_GetTicks() );
                    if(animations.at(currAnim).lastFrame()) { visible = false; }
                }
            }
        }

        rect.x = x;
        rect.y = y;

        SDL_BlitSurface(pImgManager->get(animations.at(currAnim).getCurrFrameImg()), NULL, dest, &rect);
    }
}

// Checking ovelapping...not the edges, therefor the -1
bool cSprite::overlapping(cSprite *b)
{
    if ( rect.y + rect.h - 1 < b->gety() ) { return false; }
    if ( rect.y > b->gety() + b->geth() - 1 ) { return false; }
    if ( rect.x + rect.w - 1 < b->getx() ) { return false; }
    if ( rect.x > b->getx() + b->getw() -1 ) { return false; }

return true;
}

void cSprite::setAnimation( string anim )
{
    for(int i = 0; i < animations.size(); i++)
    {
        if(animations.at(i).getName() == anim)
        {
            currAnim = i;
            return;
        }
    }
}

int cSprite::getFrame(string animation, int frame)
{
    for(int i = 0; i < animations.size(); i++)
    {
        if(animations.at(i).getName() == animation)
        {
            return animations.at(i).getFrameImg(frame);
        }
    }
}





