#include <SDL.h>
#include <string>
#include <vector>
#include "sprite_object.h"


using namespace std;


void Screenstate(bool a, SDL_Window * window, SDL_Renderer * renderer) {
		if (a) {
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			SDL_RenderSetLogicalSize(renderer, 640, 480);
		}
		else {
			SDL_SetWindowFullscreen(window, 0);
		}
}

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
	SDL_Rect mouse_rect = { 0, 0, 10, 10 }; // The rect for the mouse.
	SDL_Color screen_color = { 0,0,0,255 };
	bool keyboard = SDL_GetKeyboardState(NULL);

	//Creating a window
	window = SDL_CreateWindow("Snake Redux", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);


	//We use enum so that we can easily switch between game states
	enum Game_States { MENU = 0, CLASSIC = 1, REDUX_MODE = 2, OPTIONS = 3, FULLSCREEN = 4, QUIT = 5, BACK = 6 };

	//Buttons
	Sprite_Object menu_items[7]{
		Sprite_Object(10,-30,600,600,"Snaked_Redux_Sprites/menu.bmp", renderer),
		Sprite_Object(75,350,100,100,"Snaked_Redux_Sprites/classic.bmp", renderer),
		Sprite_Object(200,350,100,100,"Snaked_Redux_Sprites/Redux.bmp",renderer),
		Sprite_Object(500,350,100,100,"Snaked_Redux_Sprites/Option.bmp",renderer),
		Sprite_Object(400,350,100,100,"Snaked_Redux_Sprites/fullscreen.bmp",renderer),
		Sprite_Object(300,350,100,100,"Snaked_Redux_Sprites/Quit.bmp",renderer),
		Sprite_Object(500,350,100,100,"Snaked_Redux_Sprites/back.bmp",renderer)
	};
	//Power Ups

	//Event System
	Game_States state = MENU;
	while (running) {
		mouse_click = false;

		//OS Events
		SDL_PollEvent(&event); // Checking for if Quit has been activated
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;

		case SDL_MOUSEMOTION:
			mouse_rect.x = event.motion.x;
			mouse_rect.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				mouse_click = true;
				break;
			}
			break;
		}

		 //Game Events
		 switch (state) {

		 case MENU: 
			 // for when the mouse is hovering over an button or when it is clicking
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
			 break;

		 case REDUX_MODE:
			 if (menu_items[OPTIONS].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 state = OPTIONS;
				 }
			 }
			 break;

		 case OPTIONS:
			 if (menu_items[FULLSCREEN].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 if (!Fullscreen) {
						 Fullscreen = true;
					 }
					 else if (Fullscreen) {
						 Fullscreen = false;
					 }
				 }
			 }
			 break;
		 }

		 //Rendering
		 SDL_SetRenderDrawColor(renderer, screen_color.r, screen_color.g, screen_color.b, screen_color.a);
		 SDL_RenderClear(renderer);
		 switch (state) {
		 case MENU:
			 screen_color.r = screen_color.g = screen_color.b = 0;
			 menu_items[MENU].Render();
			 menu_items[CLASSIC].Render();
			 menu_items[REDUX_MODE].Render();
			 menu_items[OPTIONS].Render();
			 menu_items[FULLSCREEN].Render();
			 break;
		 case CLASSIC:
			 screen_color.r = screen_color.g = screen_color.b = 242;
			 menu_items[OPTIONS].Render();
			 break;
		 case REDUX_MODE:
			 menu_items[OPTIONS].Render();
			 break;
		 case OPTIONS:
			 menu_items[BACK].Render();
			 menu_items[FULLSCREEN].Render();

			 break;

		 }

		 //....rendering stuff goes here


		 SDL_RenderPresent(renderer);
		 




	 }
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}