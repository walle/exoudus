#include "main.h"

int main( int argc, char *arcv[])
{
    srand(time(0));
    SDL_ShowCursor(false);

    start_game();


    while(!done)
    {
        update_game();
    }

exit_game();

return 0;
}

void start_game()
{
	pLog = new cLog("Log.txt");
	pDebug = new cLog("Debug.txt");

	pSettings = new cSettings;
	pSettings->load();

	pImgManager = new cImgManager;


    if( SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0 )
    {
        pLog->write( "Couldn't initialize SDL! Reason: %s", SDL_GetError() );
        exit(1);
    }
    atexit(SDL_Quit);

    if( TTF_Init() == -1 )
    {
        pLog->write( "Could't initialize SDL_ttf! Reason: %s", TTF_GetError() );
        exit(1);
    }

    pFont = new cFont;
	pFont->init( "data/fonts/LARABIEF.TTF", 12 );

	Uint32 colorkey;
    SDL_Surface *image;

    image = SDL_LoadBMP("icon.bmp");

    colorkey = SDL_MapRGB(image->format, 0, 255, 0);

    SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorkey);

    SDL_WM_SetIcon(image,NULL);

    if(pSettings->fullscreen)
    {
        screen = SDL_SetVideoMode(pSettings->screen_w, pSettings->screen_h, pSettings->bpp, SDL_SWSURFACE | SDL_HWPALETTE | SDL_HWACCEL | SDL_RLEACCEL | SDL_FULLSCREEN);
    }
    else
    {
        screen = SDL_SetVideoMode(pSettings->screen_w, pSettings->screen_h, pSettings->bpp, SDL_SWSURFACE | SDL_HWPALETTE | SDL_HWACCEL | SDL_RLEACCEL);
    }

    if(screen == NULL)
    {
        pLog->write("Error setting the video mode %ix%ix%i! Reason: %s", pSettings->screen_w, pSettings->screen_h, pSettings->bpp, SDL_GetError());
        exit(1);
    }

    if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1 )
    {
        pLog->write("Mix_OpenAudio: %s\n", Mix_GetError());
        exit(1);
    }

    pSoundManager = new cSoundManager;
    if( !pSoundManager->addsound("data/sound/shoot.wav") )
    {
        pLog->write("Couldn't load sound" );
    }

    if( !pSoundManager->setmusic("data/music/music.ogg") )
    {
        pLog->write("Couldn't load music" );
    }

    pSoundManager->playmusic();
    pSoundManager->pausemusic();

    pMenustate = new cMenustate;
    pPlaystate = new cPlaystate;
    pOptionsstate = new cOptionsstate;

    pBackground = new cBackground;

    pGamestatemanager = new cGamestatemanager( pMenustate );

    SDL_WM_SetCaption("Exoudus","Exoudus");


}

void exit_game()
{
	if(pLog)
	{
		delete pLog;
		pLog = NULL;
	}
	if(pDebug)
	{
		delete pDebug;
		pDebug = NULL;
	}
	if(pSettings)
	{
		pSettings->save();
		delete pSettings;
		pSettings = NULL;
	}
	if(pImgManager)
	{
		delete pImgManager;
		pImgManager = NULL;
	}
	if(pSoundManager)
	{
	    delete pSoundManager;
	    pSoundManager = NULL;
	}
	if(pFont)
	{
		delete pFont;
		pFont = NULL;
	}
	if(pGamestatemanager)
	{
	    delete pGamestatemanager;
	    pGamestatemanager = NULL;
	}
	if(pMenustate)
	{
	    delete pMenustate;
	    pMenustate = NULL;
	}
	if(pPlaystate)
	{
	    delete pPlaystate;
	    pPlaystate = NULL;
	}
	if(pOptionsstate)
	{
	    delete pOptionsstate;
	    pOptionsstate = NULL;
	}
	if(pBackground)
	{
	    delete pBackground;
	    pBackground = NULL;
	}
	Mix_CloseAudio();
}

void update_game()
{
    pGamestatemanager->run();
    pGamestatemanager->process_events( event );
}
