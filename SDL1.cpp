#include <stdio.h>
#include <SDL.h>

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 800;

int main(int agrc, char* argv[]) {
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	window = SDL_CreateWindow(u8"Певнева Екатерина", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 55, 80, 100));

		SDL_Surface* myImage = SDL_LoadBMP("1.bmp");
		if (myImage == NULL)
		{
			printf("error");

		}
		SDL_Rect dest;
		dest.x = 600;
		dest.y = 700;
		SDL_SetColorKey(myImage, SDL_TRUE, SDL_MapRGB(myImage->format, 255, 255, 255));
		SDL_BlitSurface(myImage, NULL, screenSurface, &dest);
	
		

		SDL_UpdateWindowSurface(window);
		SDL_Delay(5000);
	}
	SDL_DestroyWindow(window);
	SDL_FreeSurface(screenSurface);
	SDL_Quit();

	return 1;
}