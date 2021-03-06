#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "sprite_object.h"
#include "snake.h"
#include <random>


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

	//Snake Instances
	Snake players[3]{
			Snake(WIDTH / 2, HEIGHT / 2, 20, 20, SDL_Color({0, 255, 0, 255})),
			Snake(400, 400, 20, 20, SDL_Color({255, 0, 0, 255})),
			Snake(20, 20, 20, 20, SDL_Color({0, 0, 255, 255}))
	};

	//Power Ups
	Node apple = Node(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20, 20, 20, SDL_Color({255, 0, 0, 255}));
	Node big_apple = Node(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20, 20, 20, SDL_Color({255, 0, 255, 255}));
	Node wall = Node(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20, 20, 20, SDL_Color({255, 255, 0, 255}));
	Node pellet = Node(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20, 20, 20, SDL_Color({0, 255, 255, 255}));
	Node pickups[3] = {big_apple, wall, pellet};
	vector<Node> spawned = {};


	//Event System
	Game_States state = MENU;
	while (running) {
		mouse_click = false;
		auto KEY_STATE = SDL_GetKeyboardState(NULL);

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
			 if (apple.IsTouching(& players[0].body[0].rect)){
				 apple.SetLocation(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20);
				 players[0].points += 1;
				 players[0].grow_snake(SDL_Color({0, 200, 0, 255}));
				 if (players[0].points % 5 == 0){
					 players[0].increase_speed();
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_UP]){
				 if (players[0].direction != "DOWN"){
					players[0].set_direction("UP");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_DOWN]){
				 if(players[0].direction != "UP"){
					players[0].set_direction("DOWN");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_LEFT]){
				 if (players[0].direction != "RIGHT"){
					players[0].set_direction("LEFT");
				}
			 }
			 if (KEY_STATE[SDL_SCANCODE_RIGHT]){
				 if(players[0].direction != "LEFT"){
					players[0].set_direction("RIGHT");
				 }
			 }
			 players[0].logic(false, WIDTH, HEIGHT);
			 break;

		 case REDUX_MODE:
			 if (menu_items[OPTIONS].IsTouching(&mouse_rect)) {
				 if (mouse_click) {
					 state = OPTIONS;
				 }
			 }
				//Need help with adding the collision conditions
			 if (big_apple.IsTouching(& players[1].body[0].rect)){
				 players[1].points += 3;
				 players[1].grow_snake(SDL_Color({240, 0, 0, 255}));
			 }
			 
			 if(big_apple.IsTouching(& players[2].body[0].rect)){
				 players[2].points += 3;
				 players[2].grow_snake(SDL_Color({0, 200, 0, 255}));
			 }
			 if (apple.IsTouching(& players[1].body[0].rect)){
				 apple.SetLocation(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20);
				 players[1].points += 1;
				 players[1].grow_snake(SDL_Color({200, 0, 0, 255}));
				 if (players[1].points % 5 == 0){
					 players[1].increase_speed();
				 }
			 }
			 
			 if (apple.IsTouching(& players[2].body[0].rect)){
				 apple.SetLocation(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT - 25) + 20);
				 players[2].points += 1;
				 players[2].grow_snake(SDL_Color({0, 200, 0, 255}));
				 if (players[2].points % 5 == 0){
					 players[2].increase_speed();
				 }
			 }

			 if (spawned.size() < 1){
				 spawned.push_back(pickups[rand() % 3]);
				 spawned[0].SetLocation(rand() % (WIDTH - 25) + 20, rand() % (HEIGHT -25) + 20);
			 }
			 if (spawned[0].IsTouching(& players[1].body[0].rect)){
				 spawned.pop_back();
			 }
			 if (spawned[0].IsTouching(& players[2].body[0].rect)){
				 spawned.pop_back();
			 }

			 if (KEY_STATE[SDL_SCANCODE_W]){
				 if (players[1].direction != "DOWN"){
					players[1].set_direction("UP");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_S]){
				 if(players[1].direction != "UP"){
					players[1].set_direction("DOWN");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_A]){
				 if (players[1].direction != "RIGHT"){
					players[1].set_direction("LEFT");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_D]){
				 if(players[1].direction != "LEFT"){
					players[1].set_direction("RIGHT");
				 }
			 }
			 players[1].logic(false, WIDTH, HEIGHT);
			 if (KEY_STATE[SDL_SCANCODE_UP]){
				 if (players[2].direction != "DOWN"){
					players[2].set_direction("UP");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_DOWN]){
				 if(players[2].direction != "UP"){
					players[2].set_direction("DOWN");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_LEFT]){
				 if (players[2].direction != "RIGHT"){
					players[2].set_direction("LEFT");
				 }
			 }
			 if (KEY_STATE[SDL_SCANCODE_RIGHT]){
				 if(players[2].direction != "LEFT"){
					players[2].set_direction("RIGHT");
				 }
			 }
			 players[2].logic(false, WIDTH, HEIGHT);
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
			 if (menu_items[BACK].IsTouching(&mouse_rect)){
				 if(mouse_click){
					 state = MENU;
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
			 apple.Render(renderer);
			 menu_items[OPTIONS].Render();
			 players[0].render(renderer);
			 break;

		 case REDUX_MODE:
		 	 if (spawned.size() == 1){
				  spawned[0].Render(renderer);
			  }
		 	 apple.Render(renderer);
			 menu_items[OPTIONS].Render();
			 players[1].render(renderer);
			 players[2].render(renderer);
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
