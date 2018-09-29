#include "snake.h"
#include "Node.h"
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

void Snake::grow_snake(int x, SDL_Color Node)
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

Snake::Snake(int x, int y, int w, int h, SDL_Color color)
{
	body.push_back(Node(x, y, w, h, color));
}

void Snake::render(SDL_Renderer * renderer , string filename)
{
	for (auto & part : body) {
		part.Render(renderer);
	}
}

