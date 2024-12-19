#include"Gamefile.h"
#include"TextureManager.h"
#include"Map.h"
#include"ECS.h"
#include"Components.h"
#include"Vector.h"
#include"Collision.h"
#include<iostream>
using namespace std;
SDL_Renderer*Game:: renderer=nullptr;
SDL_Event Game::event;
Map* lvlmap;
Manager manager;

std::vector<ColliderComponent*>Game::colliders;

auto& player(manager.addEntity());
auto& enemy(manager.addEntity());

const char* mapfile="asset/terrain_ss.png";

enum groupLabels :std::size_t
{
	groupMap,
	groupPlayers,
	groupEnemies,
	groupColliders
};
auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));
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
	lvlmap = new Map();
	
	Map::LoadMap("asset/map.map",25,20);

	player.addComponent<TransformComponent>(4);
	player.addComponent<SpriteComponent>("asset/player_anims.png",true);  
	player.addComponent<Controller>();
	player.addGroup(groupPlayers);
	player.addComponent<ColliderComponent>("player");


}


void Game::handleEvents() // xu li input
{
	player.addComponent<Controller>();
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
	for (auto& t : tiles)
	{
		t->draw();
	}
	for (auto& p : players)
	{
		p->draw();
	}
	for (auto& e : enemies)
	{
		e->draw();
	}
	SDL_RenderPresent(renderer);
}
void Game::update()//...
{
	manager.refresh();
	manager.update();
	/*for (auto cc : colliders)
	{
		Collision::AABB(player.getComponent<ColliderComponent>(), *cc);
	}*/
}

void Game::clean()
{
	SDL_DestroyWindow;
	SDL_DestroyRenderer;
	SDL_Quit();
	cout << "Game cleanned!";
}

void Game::AddTile(int srcX,int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos,mapfile);
	tile.addGroup(groupMap);
}
