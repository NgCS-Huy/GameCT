#pragma once
#ifndef Gamefile.h //Khoi tao cac ham chinnh
#include<SDL.h>
#include <stdio.h>
#include <iostream>
#include<SDL_image.h>
using namespace std;
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
	static SDL_Renderer* renderer;
private:
	int cnt = 0;
	bool isRunning;
	SDL_Window* window;
};
#endif 

