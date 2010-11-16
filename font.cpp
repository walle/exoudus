#include "globals.h"

cFont::cFont()
{
    img = NULL;
}   

cFont::~cFont()
{
	SDL_FreeSurface(img);
	TTF_CloseFont(font);
}  

bool cFont::init(std::string file, int size)
{
    font = TTF_OpenFont(file.c_str(), size);
    if(!font)  
    {
    	pLog->write("Couldn't load font: %s! Reason: %s \n", file.c_str(), TTF_GetError());
    	return false;
    }

return true;
}        

void cFont::write(SDL_Color color, int x, int y, const char *msg, ...)
{

    va_list args; va_start(args,msg);
    char szBuf[1024];
    vsprintf(szBuf,msg,args);
        
    img = TTF_RenderText_Solid(font, szBuf, color);
    if(img == NULL)
    {
        pLog->write("Font wrror! \n");
    }  
    
    SDL_Rect rect;        
    rect.x = x;
    rect.y = y;
            
    SDL_BlitSurface(img, NULL, screen, &rect);  
        
    va_end(args);
}           	
