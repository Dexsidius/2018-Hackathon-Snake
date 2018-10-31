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

}

void Snake::logic(bool wall, int WIDTH, int HEIGHT)
{
	if (!lost){
		if (direction == "LEFT") {
			int x = body[0].rect.x - speed;
			body[0].SetLocation(x, body[0].rect.y);
		}
		else if (direction == "RIGHT") {
			int x = body[0].rect.x + speed;
			body[0].SetLocation(x, body[0].rect.y);
		}
		else if (direction == "UP") {
			int y = body[0].rect.y - speed;
			body[0].SetLocation(body[0].rect.x, y);
		}
		else if (direction == "DOWN") {
			int y = body[0].rect.y + speed;
			body[0].SetLocation(body[0].rect.x, y);
		}
		update_children();
	}


	if (!wall) {
		if (body[0].rect.y < 2)
			body[0].SetLocation(body[0].rect.x, HEIGHT - 25);
		if (body[0].rect.y > HEIGHT - 20)
			body[0].SetLocation(body[0].rect.x, 3);
		if (body[0].rect.x < 2)
			body[0].SetLocation(WIDTH -25, body[0].rect.y);
		if (body[0].rect.x > WIDTH - 20)
			body[0].SetLocation(3, body[0].rect.y);
	}


	for (auto i = 10; i < body.size(); i++) {
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

int Snake::get_current_size(int size)
{
	size = body.size();
	return size;
}

Snake::Snake(int x, int y, int w, int h, SDL_Color color)
{
	body[0] = Node(x, y, w, h, color);
	body.push_back(Node(x - 10, y, w, h, SDL_Color({0,0,0,0})));
}

void Snake::render(SDL_Renderer * renderer)
{
	for (int i = 2; i < body.size(); i++) {
		body[i].Render(renderer);
	}
	body[0].Render(renderer);
}

void Snake::set_direction(string d){
	direction = d;
}

void Snake::increase_speed(){
	speed += 1;
}
