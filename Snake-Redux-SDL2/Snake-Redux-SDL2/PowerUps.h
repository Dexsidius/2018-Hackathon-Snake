#pragma once
#include <SDL.h>

using namespace std;

class Powerups {
private:

	
public:
	string powerups = {"pellets", "wall", "big apple"};
	void spawn_powerups(int, int, int, int, SDL_Renderer renderer, string filename);
	int shoot_pellets(int, int);
	int big_apple(int, int);
	int set_wall(int, int);
};
