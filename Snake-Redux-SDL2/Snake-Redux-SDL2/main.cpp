#include <SDL.h>
#include <string>

using namespace std;

int main(int argc, char ** argv) //Equivalent to WinMain() on Windows, this is the entry point, and initializes SDL2
{

	const int WIDTH = 640, HEIGHT = 480;

	SDL_Init(SDL_INIT_VIDEO);       //This activates a specific SDL2 subsystem  

	//Forward Declerations
	SDL_Event event;          //This is the handle for the Event Subsystem
	SDL_Window * window;      //This is a handle for the Window
	SDL_Surface * screen;
	SDL_Renderer * renderer;
	bool running = true;
	bool Fullscreen = false;

	//Mouse Rect and Click Bool
	bool mouse_click = false;
	SDL_Rect mouse_rect = SDL_Rect({ 0, 0, 10, 10 });

	//Creating a window
	 window = SDL_CreateWindow("Snake Redux", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	 renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
	 
	 
	//Event System
	 while (running) {

		 //OS Events
		 SDL_PollEvent(&event);
		 switch (event.type) {
		 case SDL_QUIT:
			 running = false;
			 break;
		 }

		 //Game Events 
		 //We use enum so that we can easily switch between game states
		 enum Game_States { MENU = 1, CLASSIC = 2, REDUX_MODE = 3
		 OPTIONS = 4};
		 Game_States state = MENU;
		 switch (state) {
		 case MENU:
			 if (SDL_HasIntersection(&mouse_rect, x.location))
				 if (mouse_click);
					state = CLASSIC;

		     if (SDL_HasIntersection(&mouse_rect, x.location))
				 if (mouse_click);
					state = REDUX_MODE;
			
			if (SDL_HasIntersection(&mouse_rect, x.location))
				if (mouse_click);
					state = OPTIONS;
		 case CLASSIC:

		 case REDUX_MODE:

		 case OPTIONS:

		 }

		 //Rendering
		 SDL_SetRenderDrawColor(renderer,242,242,242,255)


		 
		 


		 
	 }
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}