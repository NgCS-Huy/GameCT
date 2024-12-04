#pragma once
#include"Gamefile.h"
class Object {
public:
	Object(const char* textureSheet,SDL_Renderer*ren);
	~Object();
private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, desRect;
	SDL_Renderer* renderer;
};