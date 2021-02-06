#include "SDL.h"
#include "Game.h"

Game *game = nullptr;



int main(int argc, char* argv[])
{
	const int FPS = 165;
	const int frameDelay = 1000 / FPS;

	Uint64 nowTime = 0;
	Uint64 lastTime = 0;
	double deltaTime = 0.0;

	Uint32 frameStart;
	int frameTime;

	game = new Game();

	game->init("MapleEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (game->running())
	{
		lastTime = nowTime;
		nowTime = SDL_GetPerformanceCounter();
		deltaTime =  (double)((nowTime - lastTime) / (double)SDL_GetPerformanceFrequency());



		frameStart = SDL_GetTicks();
		game->handleEvent();
		game->update(deltaTime);
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	game->clean();

	return 0;


}

