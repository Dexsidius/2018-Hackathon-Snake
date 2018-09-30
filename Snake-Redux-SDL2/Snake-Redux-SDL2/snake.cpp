#include "snake.h"

using namespace std;

void Snake::set_max_size(int size)
{
	int max_size = size;

}

void Snake::set_movement(string d, int x)
{
	speed = x;
	direction = d;
}

void Snake::update_children()
{
	for (int i = 1; i < body.size(); i++) {
		body[i].SetLocation(body[i - 1].prev_location.x, body[i - 1].prev_location.y);
	}
		
}

void Snake::grow_snake( SDL_Color color)
{
	SDL_Rect location = body[int(body.size()) - 1].GetLocation();
	body.push_back(Node(location.x, location.y, location.w, location.h, color));
	SDL_free(&location);
	
}

void Snake::logic(bool wall )
{

	if (direction == "LEFT") {
		body[0].rect.x -= speed;
	}
	else if (direction == "RIGHT") {
		body[0].rect.x += speed;
	}
	else if (direction == "UP") {
		body[0].rect.y -= speed;
	}
	else if (direction == "DOWN") {
		body[0].rect.y += speed;
	}

	update_children();

	if (!wall) {
		if (body[0].rect.y < 2)
			body[0];
	}


	for (auto i = 1; i < body.size(); i++) {
		if (body[0].IsTouching(&body[i].rect)) {
			lost = true;
			break;
		}
	}



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
	body.push_back(Node(x, y, w, h, color));
}

void Snake::render(SDL_Renderer * renderer, string)
{
	for (auto & part : body) {
		part.Render(renderer);
	}
}
