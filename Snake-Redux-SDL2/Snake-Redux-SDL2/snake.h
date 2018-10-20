#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "node.h"
using namespace std;

class Snake{
private:
	string direction;
	int speed = 10;
	void set_max_size(int);
	void set_movement(string, int);
	void update_children();
	void grow_snake(SDL_Color);
	void logic(bool);


public:
	int points;
	bool lost;
	int current_size;
	int get_points(int);
	int get_current_size(int);
	vector<Node> body;

	Snake(int x, int y, int w, int h, SDL_Color color);
	void render(SDL_Renderer *, string);
};
