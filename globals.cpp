#include "globals.h"

bool done = false;
SDL_Surface *screen;
SDL_Event event;
Uint8* keys;

cFramerate framerate;

//Colors
SDL_Color red = { 255, 0, 0 };
SDL_Color green = { 0, 255, 0 };
SDL_Color blue = { 0, 0, 255 };
SDL_Color white = { 255, 255, 255 };
SDL_Color black = { 0, 0, 0 };
SDL_Color colorkey = { 0, 255, 0 };


cLog *pLog = NULL;
cLog *pDebug = NULL;
cSettings *pSettings = NULL;
cImgManager *pImgManager = NULL;
cSoundManager *pSoundManager = NULL;
cGamestatemanager *pGamestatemanager = NULL;
cMenustate *pMenustate = NULL;
cPlaystate *pPlaystate = NULL;
cOptionsstate *pOptionsstate = NULL;
cBackground *pBackground = NULL;

cFont *pFont;

bool valid_file( string filename )
{
	ifstream ifs( filename.c_str(), ios::in );

	if( ifs )
	{
		ifs.close();
		return true;
	}

	return false;
}

// Used by the valid_number function
struct nondigit
{
	bool operator() (char c) { return !isdigit(c); }
};

string int_to_string( int number )
{
	stringstream temp;
	temp << number;

	return temp.str();
}

int count(string str, string ch)
{
	int j = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str.at(i) == ch.at(0)) { j++; }
	}
return j;
}

int string_to_int( string str )
{
	int num;

	stringstream temp( str );
	temp >> num;

	return num;
}

bool pixel_collision(cSprite *sprite, int x, int y)
{
	if( ( (x >= sprite->getx()) && (x <= sprite->getx() + sprite->getw())))
	{
		if( ( (y >= sprite->gety()) && (y <= sprite->gety() + sprite->geth())))
        {
        	return true;
        }
	}
return false;
}

void Toggle_Fullscreen( void )
{
#ifdef WIN32
	Uint32 flags = screen->flags;
	flags ^= SDL_FULLSCREEN;
	Uint8 bpp = screen->format->BitsPerPixel;
	int w = screen->w;
	int h = screen->h;
	screen = SDL_SetVideoMode( w, h, bpp, flags );
#else
	// unfortunately, this command doesn't work for non-X11 platforms:
	SDL_WM_ToggleFullScreen( screen );
#endif
}

SDL_Surface *load_image(string file)
{
    SDL_Surface *temp1, *temp2;
    temp1 = IMG_Load(file.c_str());
    temp2 = SDL_DisplayFormat(temp1);
    SDL_FreeSurface(temp1);
    return temp2;
}

void draw_img( int image, int x, int y )
{
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    SDL_BlitSurface(pImgManager->get(image), NULL, screen, &rect);
}


