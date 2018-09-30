#pragma once
#include <SDL.h>

struct location { int x, y; };

class Node {
private:
	SDL_Color clr;
	
public:
	SDL_Rect rect = { 0,0,0,0 };
	location prev_location;
	Node(int x, int y, int w, int h, SDL_Color color);
	~Node();
	void SetLocation(int x, int y);
	SDL_Rect GetLocation();
	void Render(SDL_Renderer * renderer);
	bool IsTouching(SDL_Rect * rect);
};