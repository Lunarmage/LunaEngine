#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>



int main()
{
	SDL_Window *window =SDL_CreateWindow("Screen",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,780,640,SDL_WINDOW_RESIZABLE|SDL_WINDOW_OPENGL);
	//init checks
	if(!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}	
	if(glewInit() !=GLEW_OK)
	{
		throw std::exception();
	}

	std::cout<<"Hello World" <<std::endl;

	glClearColor(1.0f,1.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
	return 0;
}