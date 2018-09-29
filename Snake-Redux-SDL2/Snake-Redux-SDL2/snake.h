#pragma once
#include <iostream>
#include <SDL.h>
#include <vector>
#include "Node.h"
using namespace std;

class Snake{
private:
	void set_points(int);
	void set_current_size(int);
	void set_movement(string);
	void grow_snake(int x, SDL_Color);
	void logic();
		

public:
	int points;
	int current_size;
	int get_points(int);
	int get_current_size(int);
	vector<Node> body;
	
	Snake(int x, int y, int w, int h, SDL_Color color);
	void render(SDL_Renderer *, string);
};
