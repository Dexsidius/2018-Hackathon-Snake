#include "snake.h"
#include "PowerUps.h"

void Snake::set_points(int points)
{
	int new_points = points;
}

void Snake::set_current_size(int size)
{
	int new_size = size;
}

void Snake::set_movement(string direction)
{
}

void Snake::grow_snake(int x, SDL_Color color)
{
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
	return size;
}

void Snake::render(SDL_Renderer * renderer, string)
{
	for (auto & part : body) {
		part.Render(renderer);
	}
}
