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

	//Creating a window
	 window = SDL_CreateWindow("Snake Redux", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	 screen = SDL_GetWindowSurface(window);
	 Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
	 

	//Event System
	 while (running) {
		 screen = SDL_GetWindowSurface(window);
		 SDL_FillRect(screen, NULL, white);
		 SDL_UpdateWindowSurface(window);


		 SDL_PollEvent(&event);
		 switch (event.type) {
		 case SDL_QUIT:
			 running = false;
			 break;
		 }
			 
		 
	 }
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}