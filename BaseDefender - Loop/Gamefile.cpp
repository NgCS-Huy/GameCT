#include "Gamefile.h"
Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	};
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		cout << "Subsystem initialized.." << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "Window created" << endl;
		}
		renderer = SDL_CreateRenderer(window, -1,0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created" << endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
}
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::render()
{
	SDL_RenderClear(renderer); //Them vao render
	SDL_RenderPresent(renderer);
}
void Game::update()
{
	cnt++;
	cout << cnt;
}
void Game::clean()
{
	SDL_DestroyWindow;
	SDL_DestroyRenderer;
	SDL_Quit();
	cout << "Game cleanned!";
}