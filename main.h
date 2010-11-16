#ifndef MAIN_H
#define MAIL_H

#include "globals.h"

void start_game();
void exit_game();

void process_events();
void process_input();

void update_game();

void key_up( SDLKey key );
void key_down( SDLKey key );

#endif
