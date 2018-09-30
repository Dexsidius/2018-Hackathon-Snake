#include "Sprite_Object.h"

Sprite_Object::Sprite_Object(int x, int y, int w, int h, string filepath, SDL_Renderer * renderer)
{
	texture = cache.Load_Sprites(renderer, filepath);
	rect.x = x;
	rect.h = h;
	rect.w = w;
	rect.h = h;
	context = renderer;
}

void Sprite_Object::Render()
{
	SDL_RenderCopy(context, texture, NULL, &rect);
}

SDL_Rect * Sprite_Object::GetRect()
{
	return &rect;
}

bool Sprite_Object::IsTouching(SDL_Rect * object)
{
	return SDL_HasIntersection(object, &rect);
}
