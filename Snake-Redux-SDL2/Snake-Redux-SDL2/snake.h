#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "node.h"
using namespace std;

class Snake{
private:
	int speed = 5;
	void set_max_size(int);
	void set_movement(string, int);
	void update_children();


public:
	int points;
	bool lost;
	int current_size;
	void increase_speed();
	void logic(bool, int width = 0, int height = 0);
	void grow_snake(SDL_Color);
	int get_points(int);
	int get_current_size(int);
	void set_direction(string);

	string direction;
	vector<Node> body = {Node(0, 0, 20, 20, SDL_Color({100, 0, 0, 0}))};

	Snake(int x, int y, int w, int h, SDL_Color color);
	void render(SDL_Renderer *);
};
