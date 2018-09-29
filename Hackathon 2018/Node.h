#pragma once
#include <SDL.h>


class Node {
private:
	SDL_Color clr;
public:
	~Node();
	SDL_Rect rect = { 0,0,0,0 };

	Node(int x, int y, int w, int h, SDL_Color  color);
	void SetLocation(int x, int y);
	SDL_Rect GetLocation();
	void Render(SDL_Renderer * renderer);
	bool IsTouching(SDL_Rect * rect);
};