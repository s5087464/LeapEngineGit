#include "Keyboard.h"
#include "Core.h"

namespace myengine
{
	void Keyboard::OnTick()
	{
		m_keysPressed.clear();
		m_keysReleased.clear();

		// Create SDL event and enter while loop
		SDL_Event e = { 0 };
		while (SDL_PollEvent(&e))
		{
			
			// Add the keys released then remove from keys
			if (e.type == SDL_KEYUP)
			{
				m_keysReleased.push_back(e.key.keysym.sym);

				for (auto it = m_keys.begin(); it != m_keys.end(); it++)
				{
					if ((*it) == e.key.keysym.sym)
					{
						it = m_keys.erase(it);
					}
				}
			}
			// Add the keys pressed then add to keys
			if (e.type == SDL_KEYDOWN)
			{
				m_keysPressed.push_back(e.key.keysym.sym);

				for (auto it = m_keys.begin(); it != m_keys.end(); it++)
				{
					if ((*it) != e.key.keysym.sym)
					{
						m_keys.push_back(e.key.keysym.sym);
					}
				}
			}
		}
	}

	bool Keyboard::GetKey(SDL_Keycode _keycode)
	{
		// Iterates through the list of keys
		for (auto it = m_keys.begin(); it != m_keys.end(); it++)
		{
			if ((*it) == _keycode)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::GetKeyPressed(SDL_Keycode _keycode)
	{
		// Iterates through the list of keys to check if they're pressed
		for (auto it = m_keysPressed.begin(); it != m_keysPressed.end(); it++)
		{
			if ((*it) == _keycode)
			{
				return true;
			}
		}
		return false;
	}

	bool Keyboard::GetKeyReleased(SDL_Keycode _keycode)
	{
		// Iterates through the list of keys to check if they're released
		for (auto it = m_keysReleased.begin(); it != m_keysReleased.end(); it++)
		{
			if ((*it) == _keycode)
			{
				return true;
			}
		}
		return false;
	}
}
