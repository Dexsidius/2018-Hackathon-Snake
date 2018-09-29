#pragma once
#include <SDL.h>
#include <map>
using namespace std;

class SpriteCache {
private:
	map<string, SDL_Texture *> sprite_cache;
	SpriteCache();
public:
	SDL_Texture * Load_Sprites(SDL_Renderer * renderer, string filename);
}cache;
