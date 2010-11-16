#ifndef IMG_MANAGER_H
#define IMG_MANAGER_H

#include "globals.h"

class image
{
	public:
        image() { img = NULL; path=""; id=0; }
        ~image() { }
        SDL_Surface *img;
        string path;
        int id;
};

class cImgManager
{
	public:
        cImgManager();
        ~cImgManager();
        
        int add(string path);
        
        SDL_Surface* get(string path);
        SDL_Surface* get(int id);
        
        string get_path(int id);
        int get_id(string path);
        
        //operator overloading to get images
        SDL_Surface* operator[] (const int id) const;
        
        void remove(string path);
        void remove(int id);
        void remove_all();
        
        int size() { return images.size(); }
    private:
        vector<image> images;
};

#endif
