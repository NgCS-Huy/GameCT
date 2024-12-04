#pragma once
#include "Gamefile.h"
class Map {
public:
	Map();
	~Map();
	void LoadMap(int arr[25][25]);
	void DrawMap();
private:
	SDL_Rect src, des;
	SDL_Texture*dirt;
	SDL_Texture*water;
	SDL_Texture*grass;
	int map[25][25];
};