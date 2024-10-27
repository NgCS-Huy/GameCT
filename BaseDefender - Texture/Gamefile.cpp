#include"Gamefile.h"
#include"TextureManager.h"
SDL_Texture* botTexture;
SDL_Rect srcR, desR;
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
		renderer = SDL_CreateRenderer(window, -1,0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created" << endl;
		}
		isRunning = true;	
		botTexture = TextureManager::LoadTexture("asset/batmodel.png", renderer);
	}
	
	else {
		isRunning = false;
	}
	
}

void Game::handleEvents() // xu li input
{
	SDL_Event event;
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
	SDL_RenderCopy(renderer, botTexture, NULL, &desR);
	SDL_RenderPresent(renderer);
}
void Game::update()//...
{
	cnt++;
	desR.h = 64; // Edit chieu cao
	desR.w = 32;// edit chieu rong 
	desR.x = cnt; // di chuyen theo truc x
	//desR.y = cnt; di chuyen theo truc y
	cout << cnt << endl;//auto di chuyen
}
void Game::clean()
{
	SDL_DestroyWindow;
	SDL_DestroyRenderer;
	SDL_Quit();
	cout << "Game cleanned!";
}

