#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "globals.h"

struct sound
{
    int id;
    std::string path;
    Mix_Chunk *snd;
};

struct music
{
    std::string path;
    Mix_Music *music;
};

class cSoundManager
{
    public:
        cSoundManager();
        ~cSoundManager();

        bool addsound(std::string path);   // Add a sound to the vector
        bool setmusic(std::string path);   // Add music to the vector
        Mix_Chunk* getsound(std::string path);   // Get a pointer to the sound using the path
        Mix_Chunk* getsound(int id);   // Get a pointer to the sound using the id number
        Mix_Music* getmusic() { return m_music.music; }   // Get the music
        bool unloadsound(std::string path);  // Unload the sound using the path
        bool unloadsound(int id);   // Unload the sound using the id number
        void unloadmusic();  // Unload the music
        void unloadall();   // Unload everything
        int sounds() { return m_sounds.size(); }   // Returns how many sounds the manager have loaded

        void playsound(std::string path, int loops);
        void playsound(int id, int loops);

        void playmusic();
        void pausemusic();
        void resumemusic();
      private:
        int m_channels;
        std::vector<sound> m_sounds;
        music m_music;
};



#endif
