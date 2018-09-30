#include "Node.h"

Node::~Node()
{
	SDL_free(&rect);
}

Node::Node(int x, int y, int w, int h, SDL_Color color)
{
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	prev_location.x = rect.x;
	prev_location.y = rect.y;

}

void Node::SetLocation(int x, int y)
{
	prev_location.x = rect.x;
	prev_location.y = rect.y;
	rect.x = x;
	rect.y = y;
}

SDL_Rect Node::GetLocation()
{
	return rect;
}

void Node::Render(SDL_Renderer * renderer)
{
	SDL_SetRenderDrawColor(renderer, clr.r, clr.g, clr.b, clr.a);
	SDL_RenderFillRect(renderer, &rect);
}

bool Node::IsTouching(SDL_Rect * object)
{
	return SDL_HasIntersection(&rect, object);
}
