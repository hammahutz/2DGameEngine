#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, float x, float y);
	~GameObject();

	void Update(double deltaTime);
	void Render();

private:
	float xPos;
	float yPos;

	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

