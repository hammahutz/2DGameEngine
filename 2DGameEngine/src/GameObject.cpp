#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, float x, float y)
{
	renderer = ren;
	texture = TextureManager::LoadTexture(textureSheet, renderer);

	xPos = x;
	yPos = y;

	srcRect.x = 0;
	srcRect.y = 0;
	destRect.x = xPos;
	destRect.y = yPos;

	srcRect.h = 32;
	srcRect.w = 32;
	destRect.w = 128;
	destRect.h = 128;
}

GameObject::~GameObject()
{
}

void GameObject::Update(double deltaTime)
{
	if (deltaTime < 1)
	{
		xPos = xPos + 1 * deltaTime * 100;
		yPos = yPos + 1 * deltaTime * 100;

		std::cout << xPos << std::endl;

		destRect.x = xPos;
		destRect.y = yPos;
	}

}


void GameObject::Render()
{
	SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
