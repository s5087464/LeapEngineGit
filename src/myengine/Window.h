#include <rend/rend.h>
#include <SDL2/SDL.h>

namespace myengine
{
	struct Window
	{
		Window();
		~Window();

	private:
		friend struct Core;
		SDL_Window* m_raw;
		SDL_RendContext m_context;

		Window(const Window& _copy);
		Window& operator=(const Window& _assign);
	};

}