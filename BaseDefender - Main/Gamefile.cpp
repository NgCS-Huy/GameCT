#include"Gamefile.h"
#include"TextureManager.h"
#include"Map.h"
#include"ECS.h"
#include"Components.h"
#include"Vector.h"
SDL_Renderer*Game:: renderer=nullptr;
SDL_Event Game::event;
Map* map;
Manager manager;
auto& champion(manager.addEntity());
Game::Game()
{}
Game::~Game()
{}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) //Ham tao cua so game
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
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				cout << "Renderer created" << endl;
			}
			isRunning = true;
			
		}
	
	}
	map = new Map();
	champion.addComponent<TransformComponent>();
	champion.addComponent<SpriteComponent>("asset/ArcherIcon.png");  
	champion.addComponent<Controller>();
}


void Game::handleEvents() // xu li input
{
	champion.addComponent<Controller>();
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		SDL_DestroyTexture;
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::render() //Render model
{
	SDL_RenderClear(renderer); //Them vao render
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::update()//...
{
	manager.refresh();
	manager.update();
	
}
void Game::clean()
{
	SDL_DestroyWindow;
	SDL_DestroyRenderer;
	SDL_Quit();
	cout << "Game cleanned!";
}

