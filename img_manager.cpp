#include "globals.h"

cImgManager::cImgManager()
{
	images.clear();
}

cImgManager::~cImgManager()
{
	remove_all();
}

int cImgManager::add(string path)
{
	for(int i = 0; i < size(); i++)
	{
		if(path == images.at(i).path) { return i; }
    }
	image temp;
	temp.img = load_image(path);
	if(temp.img != NULL) 
	{
		temp.path = path;
        temp.id = images.size();
	
        images.push_back(temp);
        return images.size()-1;
	}
	else
	{
        pLog->write("Couldn't load image: %s", path.c_str());
	}
}

SDL_Surface* cImgManager::get(string path)
{
	for(int i = 0; i < size(); i++)
	{
		if(path == images.at(i).path) { return images.at(i).img; }
	}
	return NULL;
}

SDL_Surface* cImgManager::get(int id)
{
	if(id < images.size())
	{
		return images.at(id).img;
	}
	return NULL;
}

string cImgManager::get_path(int id)
{
	if(id < images.size())
	{
		return images.at(id).path;
	}
}

int cImgManager::get_id(string path)
{
	for(int i = 0; i < size(); i++)
	{
		if(path == images.at(i).path) { return i; }
	}
}

SDL_Surface* cImgManager::operator [] (const int id) const
{
	return images.at(id).img;
}

void cImgManager::remove(string path)
{
	for(int i = 0; i < size(); i++)
	{
		//if(path == images.at(i).path) {  images.erase(i); }
	}
}

void cImgManager::remove(int id)
{
	//images.erase(id);
}

void cImgManager::remove_all()
{
	for(int i = 0; i < images.size(); i++)
	{
		SDL_FreeSurface(images.at(i).img);
	}
	images.clear();
}
