#pragma once
#include<SDL.h>
#include"ECS.h"
#include"ColliderComponent.h"
#include"Vector.h"

class Collision
{
public:
	static bool AABB(const SDL_Rect& recA,const  SDL_Rect& recB);
	static bool AABB(const ColliderComponent& colA, const ColliderComponent& colB);
};