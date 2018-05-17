#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2\SDL.h>
#include <string>


class Display
{
	public: 
		Display(int width, int height, const std::string& title);	
		virtual ~Display();

		void SwapBuffers();
		void Update();

		bool IsClosed();
	
	private:
		Display(const Display& other) {}
		Display & operator=(const Display& other) {}

		SDL_Window* window;
		SDL_GLContext glContext;

		bool bIsClosed;
		

};

#endif //DISPLAY_H