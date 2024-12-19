#pragma once
#ifndef Gamefile.h //Khoi tao cac ham chinnh
#include<SDL.h>
#include <iostream>
#include<SDL_image.h>
#include<vector>

using namespace std;
class ColliderComponent; 
class Game {
public:
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() { return isRunning; }
	static void AddTile(int srcX, int srcY, int xpos, int ypos);
	static SDL_Renderer* renderer;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders;
private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
};
#endif 


