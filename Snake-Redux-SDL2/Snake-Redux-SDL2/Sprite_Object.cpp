#include "Sprite_Object.h"



Sprite_Object::Sprite_Object(int x, int y, int w, int h, string filepath, SDL_Renderer * renderer)
{
	texture = cache.Load_Sprites(renderer, filepath);
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	
}

void Sprite_Object::Render(SDL_Renderer * renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Rect * Sprite_Object::GetRect()
{
	return &rect;
}

bool Sprite_Object::IsTouching(SDL_Rect * object)
{
	return SDL_HasIntersection(object, &rect);
}
