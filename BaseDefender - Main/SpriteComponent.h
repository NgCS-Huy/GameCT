#pragma once
#include"Components.h"
#include<SDL.h>
#include"TextureManager.h"
#include"Animation.h"
#include<map>
class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, desRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;
public:

	int animIndex = 0;

	std::map < const char*, Animation >animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}
	SpriteComponent(const char* path, bool isAnimated)
	{
		animated = isAnimated;

		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1, 8, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Walk", walk);

		Play("Idle");
		
		setTex(path);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void init() override 
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;

	}
	void update() override 
	{
		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}
		srcRect.y = animIndex * transform->height;

		desRect.x = (int)transform->position.x;
		desRect.y = (int)transform->position.y;

		desRect.w = transform->width * transform->scale;
		desRect.h = transform->height * transform->scale;
	}
	void draw() override 
	{
		TextureManager::Draw(texture, srcRect, desRect, spriteFlip);
	}
	void Play(const char* aniName)
	{
		frames = animations[aniName].frames;
		animIndex = animations[aniName].index;
		speed = animations[aniName].speed;
	}
};