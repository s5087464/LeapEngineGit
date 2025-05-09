#include "Core.h"
#include "Entity.h"
#include "Window.h"
#include "Transform.h"
#include "TransformA.h"
#include "HandTransform.h"
#include "LeapInitialize.h"
#include "Resources.h"
#include "Sound.h"

#include "SDL2/SDL.h"
#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>

namespace myengine
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_window = std::make_shared<Window>();
		rtn->m_resources = std::make_shared<Resources>();

		// Audio
		rtn->m_sound = std::make_shared <Sound>();
		
		// Audio Initialization
		ALCdevice* device = alcOpenDevice(NULL);
		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}
		ALCcontext* context = alcCreateContext(device, NULL);
		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}
		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		/*void PlaySound(const std::shared_ptr<Sound>&m_sound)
		{
			ALuint source = m_sound->GetSource();
			alSourcePlay(source);
		}*/

		// Model
		// rtn->m_model = std::make_shared <Model>();

		// Leap
		std::shared_ptr<LeapInitialize> li;
		li->OnConnect();
		li->OnDevice();

		rtn->m_self = rtn;



		return rtn;
	}

	std::shared_ptr<Entity> Core::add_entity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_self = rtn;
		rtn->m_core = m_self;
		m_entities.push_back(rtn);

		rtn->add_component<Transform>();
		rtn->add_component<TransformA>();
		// rtn->add_component<LeapInitialize>();
		rtn->add_component<HandTransform>();
		
		std::cout << rtn->m_core.lock().get() << std::endl;

		return rtn;
	}

	void Core::run()
	{
		bool quit = false;
		float angle = 0;

		while (!quit)
		{
			SDL_Event event = { 0 };

			// std::shared_ptr<Keyboard> m_keyboard->OnTick();

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					sys::out("Event\n");
				}
			}


			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->tick();
			}

			SDL_Rend_ClearWindow(m_window->m_raw);



			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities.at(ei)->render();
			}

			SDL_Rend_SwapWindow(m_window->m_raw);
		}
	}

	std::shared_ptr<Window> Core::window() const
	{
		return m_window;
	}

	std::shared_ptr<Resources> Core::resources() const
	{
		return m_resources;
	}




}