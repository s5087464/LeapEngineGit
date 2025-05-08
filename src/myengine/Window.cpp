#include "Window.h"

#include <stdexcept>

namespace myengine
{

	Window::Window()
	{
		int winw = 1200;
		int winh = 800;

		m_raw = SDL_CreateWindow("MyEngine Demo",
		  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		  winw, winh, SDL_WINDOW_RESIZABLE | SDL_WINDOW_REND);

		if(!m_raw)
		{
			throw std::runtime_error("Faild to create window");
		}

		m_context = SDL_Rend_CreateContext(m_raw);

		if (!m_context)
		{
			throw std::runtime_error("Failed to create Rend context");
		}

	}

	Window::~Window()
	{
		SDL_Rend_DeleteContext(m_context);
		SDL_DestroyWindow(m_raw);
		SDL_Quit();
	}

}