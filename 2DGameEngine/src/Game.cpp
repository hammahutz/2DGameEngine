#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* player;
int cnt;

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen)
{
	int flags = 0;
	cnt = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}


	if (SDL_Init(SDL_INIT_EVERYTHING) ==  0)
	{
		std::cout << "Subsystems Initialised :D" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, widht, height, flags);
		if (window)
		{
			std::cout << "Window Created (:" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
			std::cout << "Renderer created :3" << std::endl;
		}


		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	player = new GameObject("assets/sprites/smile.png", renderer, 10, 10);
}

void Game::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
			isRunning = false;
			break;
	default:
		break;
	}
}

void Game::update(double deltaTime)
{
	player->Update(deltaTime);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	player->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned :o)" << std::endl;
}
