#pragma once

#include "Gamefile.h"

class GameObject {
public:
	GameObject(const char* texturesheet,int x, int y);
	~GameObject();

	void Update();
	void Render();
private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, desRect;
	SDL_Renderer* renderer;
};
