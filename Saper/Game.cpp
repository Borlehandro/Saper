#include "Game.h"

void Game::parseEvent(SDL_Event& event) {

	switch (event.type) {
		
	case(SDL_QUIT):
		run = false;
		break;

	case(SDL_MOUSEBUTTONDOWN):
		switch (event.button.button) {

		case (SDL_BUTTON_LEFT):
			std::cout << "Mouse left" << std::endl;
			break;

		case (SDL_BUTTON_RIGHT):
			std::cout << "Mouse right" << std::endl;
			break;

		}

		break;
	}
}

int Game::onPreload() {

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return 2;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << SDL_GetError() << std::endl;
		return 3;
	}

	background = textureManager->LoadImage(renderer, "./Textures/test.bmp");

	Field *field = new Field(5, 3, renderer);

	return 0;
}

void Game::onRun() {

	SDL_Event event;

		while (run) {

			SDL_WaitEvent(&event);
			parseEvent(event);

			textureManager->ApplySurface(0, 0, background, renderer);
		}

	SDL_Quit();
}

bool Game::isRun() {
	return run;
}
