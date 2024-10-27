
#include "G_object.h"
#include "TextureManager.h"
GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}
void GameObject::Render() {
	SDL_RenderCopy(Game::renderer, objTexture,&srcRect,&desRect);
}
void GameObject::Update() {
	
	xpos++;
	ypos++;
	srcRect.h = 4000;
	srcRect.w = 4000;
	srcRect.x = 0;
	srcRect.y = 0;

	desRect.x = xpos;
	desRect.y = ypos;
	desRect.w = 64;
	desRect.h = 64;
}

