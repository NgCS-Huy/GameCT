#include "Map.h"
#include "TextureManager.h"
 
int lvl1[20][25]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,},
	{0,0,1,1,1,1,1,1,1,2,2,2,1,1,1,1,1,1,1,1,1,2,2,0,0,},
	{0,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,1,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,2,2,2,2,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
	{0,1,1,1,1,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
	{0,1,1,1,1,2,2,1,1,1,1,1,2,2,2,1,2,1,1,1,2,2,2,2,0,},
};
Map::Map()
{
	dirt = TextureManager::LoadTexture("asset/dirt.png");
	grass = TextureManager::LoadTexture("asset/grass.png");
	water = TextureManager::LoadTexture("asset/water.png");
	LoadMap(lvl1);
	src.x = src.y = 0;
	src.w = des.w = 32;
	src.h = des.h = 32;

	des.x = des.y = 0;

};
void Map::LoadMap(int arr[20][25])
{
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
	
}
void Map::DrawMap()// Ve map theo pixel (3 gia tri 0,1,2 theo switch case)
{
	int type = 0;
	for (int row = 0; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			type = map[row][column];
			des.x = column * 32;
			des.y = row * 32;

			switch (type) {
			case 0:
				TextureManager::Draw(water, src, des);
				break;
			case 1:
				TextureManager::Draw(grass, src, des);
				break;
			case 2:
				TextureManager::Draw(dirt, src, des);
				break;
			default:
				break;
			}
		}
	}
}