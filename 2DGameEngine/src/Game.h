#pragma once
#include "SDL.h"
#include <iostream>
#include "SDL_image.h"


class Game
{

public:

	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int widht, int height, bool fullscreen);
	void handleEvent();
	void update(double deltaTime);
	void render();
	void clean();

	bool running() {return isRunning;};

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

