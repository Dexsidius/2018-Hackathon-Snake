#include <SDL.h>
#include <string>
#include <vector>
#include "Sprite_Object.h"


using namespace std;

int main(int argc, char ** argv) //Equivalent to WinMain() on Windows, this is the entry point, and initializes SDL2
{
	SDL_Init(SDL_INIT_VIDEO);       //This activates a specific SDL2 subsystem  

	//Forward Declerations
	const int WIDTH = 640, HEIGHT = 480; //The variable dimensions for the window.
	SDL_Event event;          //This is the handle for the Event Subsystem
	SDL_Window * window;      //This is a handle for the Window
	SDL_Surface * screen;
	SDL_Renderer * renderer;
	bool running = true;	  // The bool to start the while loop for the game.
	bool Fullscreen = false;  // The bool that we use to change to fullscreen.
	bool mouse_click = false; // The bool thatwe use to show mouse inputs.
	SDL_Rect mouse_rect = SDL_Rect({ 0, 0, 10, 10 }); // The rect for the mouse.
	bool keyboard = SDL_GetKeyboardState(NULL); 

	//Creating a window
	 window = SDL_CreateWindow("Snake Redux", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	 renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_PRESENTVSYNC);
	 
	//Buttons
	 Sprite_Object menu_items[3]{
		 Sprite_Object(0,0,600,600,"Snaked_Redux_Sprites/menu.bmp", renderer),
		 Sprite_Object(300,600,100,100,"Snaked_Redux_Sprites/classic.bmp", renderer),
		 Sprite_Object(200,200,100,100,"Snaked_Redux_Sprites/Redux.bmp",renderer),
	 };
	//Power Ups
	 
	//Event System
	 while (running) {

		 //OS Events
		 SDL_PollEvent(&event); // Checking for if Quit has been activated
		 switch (event.type) {
		 case SDL_QUIT:
			 running = false;
			 break;
		 }

		 //Game Events 
		 //We use enum so that we can easily switch between game states
		 enum Game_States { MENU = 0, CLASSIC = 1, REDUX_MODE = 2, OPTIONS = 3 };
		 Game_States state = MENU;
		 switch (state) {
		 case MENU: // Cases for when the mouse is hovering over an button or when it is clicking
			 if (menu_items[CLASSIC].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 state = CLASSIC;
				 }	
			 }
			 else if (menu_items[REDUX_MODE].IsTouching(&mouse_rect)) {
				 if (mouse_click)
					 state = REDUX_MODE;
			 }
			 else if (menu_items[OPTIONS].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 state = OPTIONS;
				 }
			 }
			 break;
				 
		 case CLASSIC:
			 if (menu_items[OPTIONS].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 state = OPTIONS;
				 }
			 }
		 case REDUX_MODE:
			 if (menu_items[OPTIONS].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 state = OPTIONS;
				 }
			 }

		 case OPTIONS:
			 break;
		 }

		 //Rendering
		 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		 SDL_RenderClear(renderer);
		 switch (state) {
		 case MENU:
			 SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			 menu_items[MENU].Render(renderer);
			 menu_items[CLASSIC].Render(renderer);
			 menu_items[REDUX_MODE].Render(renderer);
			 break;
		 case CLASSIC:
			 break;
		 case REDUX_MODE:
			 break;
		 case OPTIONS:
			 break;

		 }

		 //....rendering stuff goes here


		 SDL_RenderPresent(renderer);
		 




	 }
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}