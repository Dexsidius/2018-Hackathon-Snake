#include "SpriteCache.h"

SpriteCache::~SpriteCache()
{
	for (auto item : sprite_cache) {
		SDL_DestroyTexture(item.second);
	}
}

SDL_Texture * SpriteCache::Load_Sprites(SDL_Renderer * renderer, string filename)
{
	if (!sprite_cache.count(filename)) {
		SDL_Surface * surface = SDL_LoadBMP(filename.c_str());
		sprite_cache[filename] = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_free(surface);
	}
	return sprite_cache[filename];
}
