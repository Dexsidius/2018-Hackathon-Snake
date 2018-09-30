#pragma once
#include <SDL.h>
#include <string>
#include "SpriteCache.h"

using namespace std;

class Sprite_Object {
private:
	SDL_Rect rect = {0,0,0,0};
	SDL_Texture * texture;
	SDL_Renderer * context;
public:
	Sprite_Object(int x, int y, int w, int h, string filepath, SDL_Renderer* renderer);
	void Render(SDL_Renderer*renderer);
	SDL_Rect * GetRect();
	bool IsTouching(SDL_Rect*object);
};

