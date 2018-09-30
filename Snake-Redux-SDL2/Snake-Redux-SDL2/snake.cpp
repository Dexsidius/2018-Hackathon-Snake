#include "snake.h"
#include "PowerUps.h"

using namespace std;

void Snake::set_points(int points)
{
	int new_points = points;
}

void Snake::set_current_size(int size)
{
	int new_size = size;
}

void Snake::set_movement(string direction, int x)
{
	
}

void Snake::grow_snake(int x, SDL_Color color)
{
	for (auto & part : body) {
		if (part == NULL) {

		}
		
	}
}

void Snake::logic()
{
}

int Snake::get_points(int points)
{
	return points;
}

int Snake:: get_current_size(int size)
{
	size = body.size();
	return size;
}

Snake::Snake(int x, int y, int w, int h, SDL_Color color)
{
}

void Snake::render(SDL_Renderer * renderer, string)
{
	for (auto & part : body) {
		part.Render(renderer);
	}
}
