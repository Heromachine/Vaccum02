#include <iostream>
#include "display.h"
#include <GL\glew.h>


Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


	window = SDL_CreateWindow //CONTINUED->
	(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);

	glContext = SDL_GL_CreateContext(window);

	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cerr << "GLEW FAILED" << std::endl;
	}

	bIsClosed = false;
}


Display::~Display()
{
	SDL_GL_DeleteContext(glContext);
	SDL_GL_DeleteContext(window);
	SDL_Quit();
}

void Display::Update()
{
	SDL_GL_SwapWindow(window);
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			bIsClosed = true;
		}
	}

}
void Display::SwapBuffers()
{
	SDL_GL_SwapWindow(window);

}

bool Display::IsClosed()
{
	return bIsClosed;
}