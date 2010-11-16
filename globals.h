#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
#include <stdarg.h>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;
using std::fstream;
using std::ofstream;
using std::ios;

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "framerate.h"
#include "img_manager.h"
#include "sound_manager.h"
#include "log.h"
#include "settings.h"
#include "font.h"
#include "tinyxml.h"
#include "frame.h"
#include "animation.h"
#include "sprite.h"
#include "image.h"
#include "vector2d.h"
#include "bullet.h"
#include "ship.h"
#include "player.h"
#include "enemy.h"
#include "background.h"
#include "gamestate.h"
#include "gamestatemanager.h"
#include "menustate.h"
#include "playstate.h"
#include "optionsstate.h"



extern bool done;
extern SDL_Surface *screen;
extern SDL_Event event;
extern Uint8* keys;

extern cFramerate framerate;

extern SDL_Color red, green, blue, white, black, colorkey;

extern cLog *pLog;
extern cLog *pDebug;
extern cSettings *pSettings;
extern cImgManager *pImgManager;
extern cSoundManager *pSoundManager;
extern cGamestatemanager *pGamestatemanager;
extern cMenustate *pMenustate;
extern cPlaystate *pPlaystate;
extern cOptionsstate *pOptionsstate;
extern cBackground *pBackground;

extern cFont *pFont;


// Checks if the file exists
bool valid_file(string filename);

// Checks if the string is a number
bool valid_number(string num);

// Counts the number of specified string in a string
int count(string str, string ch);

// Returns the number as a string
string int_to_string(int number);

// Returns the string as a number
int string_to_int(string str);

// Checks if a pixel is inside a cSprite
bool pixel_collision(cSprite *sprite, int x, int y);

// Changes between fullscreen and windowed mode
void Toggle_Fullscreen( void );

// Loads an image
SDL_Surface *load_image(string file);

//Draws an image
void draw_img( int image, int x, int y );


#endif
