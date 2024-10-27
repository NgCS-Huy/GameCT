#pragma once
#include"Gamefile.h"
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};