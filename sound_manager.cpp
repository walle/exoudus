#include "globals.h"

cSoundManager::cSoundManager()
{
    m_sounds.clear();
    m_channels=0;
    Mix_VolumeMusic(30);
}

cSoundManager::~cSoundManager()
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        Mix_FreeChunk(m_sounds.at(i).snd);
    }
    Mix_FreeMusic(m_music.music);
    m_sounds.clear();
    m_channels=0;
}

bool cSoundManager::addsound(std::string path)
{
    sound temp;
    temp.path=path;
    temp.id=m_sounds.size()+1;
    temp.snd=Mix_LoadWAV(path.c_str());
    if(!temp.snd)
    {
        //error
        return false;
    }
    m_sounds.push_back(temp);
    m_channels++;
    Mix_AllocateChannels(m_channels);
return true;
}

bool cSoundManager::setmusic(std::string path)
{
    m_music.path=path;
    m_music.music=Mix_LoadMUS(path.c_str());
    if(!m_music.music)
    {
        //error
        return false;
    }
return true;
}

/*Mix_chunk* sound_manager::getsound(std::string path)
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        if(path==m_sounds.at(i).path) { return m_sounds.at(i).snd; }
    }
}

Mix_chunk* sound_manager::getsound(int id)
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        if(id==m_sounds.at(i).id) { return m_sounds.at(i).snd; }
    }
} */

bool cSoundManager::unloadsound(std::string path)
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        if(path==m_sounds.at(i).path) { Mix_FreeChunk(m_sounds.at(i).snd);  return true;}
    }
return false;
}

bool cSoundManager::unloadsound(int id)
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        if(id==m_sounds.at(i).id) { Mix_FreeChunk(m_sounds.at(i).snd);  return true;}
    }
return false;
}

void cSoundManager::unloadmusic()
{
    Mix_FreeMusic(m_music.music);
}

void cSoundManager::unloadall()
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        Mix_FreeChunk(m_sounds.at(i).snd);
    }
    m_sounds.clear();
    Mix_FreeMusic(m_music.music);
}

void cSoundManager::playsound(std::string path, int loops)
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        if(path==m_sounds.at(i).path) {  Mix_PlayChannel(i, m_sounds.at(i).snd, loops); }
    }
}

void cSoundManager::playsound(int id, int loops)
{
    for(int i=0; i<m_sounds.size(); i++)
    {
        if(id==m_sounds.at(i).id) {  Mix_PlayChannel(i, m_sounds.at(i).snd, loops); }
    }
}

void cSoundManager::playmusic()
{
    Mix_PlayMusic(m_music.music, -1);
}

void cSoundManager::pausemusic()
{
    Mix_PauseMusic();
}

void cSoundManager::resumemusic()
{
    Mix_ResumeMusic();
}
