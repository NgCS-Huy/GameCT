#pragma once
#include "Gamefile.h"
class Map {
public:
	Map();
	~Map();
	void LoadMap(int arr[20][25]);
	void DrawMap();
private:
	SDL_Rect src, des;
	SDL_Texture*dirt;
	SDL_Texture*water;
	SDL_Texture*grass;
	int map[20][25];
};