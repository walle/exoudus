#ifndef SETTINGS_H
#define SETTINGS_H

#include "globals.h"

#define FILENAME "settings.cfg"

class cSettings
{
	public:
        cSettings();
        ~cSettings();

        // Public functions
        bool load();
        void save();
        void standard();

        // Public variables
        int screen_w, screen_h, bpp;
        bool fullscreen, showfps;
        SDLKey up, down, left, right;

    private:
    void parse(string command, int line);
	bool apply(string *parts, unsigned int count, unsigned int line);
};

#endif
