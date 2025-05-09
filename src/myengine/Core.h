#include <memory>
#include <vector>

namespace myengine
{
	struct Entity;
	struct Window;
	struct Resources;

	struct Sound;
	struct Model;
	struct Keyboard;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		
			
		void run();
		std::shared_ptr<Entity> add_entity();
		std::shared_ptr<Window> window() const;
		std::shared_ptr<Resources> resources() const;
		//void PlaySound(const std::shared_ptr<Sound>& m_sound);

	private:
		std::vector< std::shared_ptr<Entity> > m_entities;
		std::weak_ptr<Core> m_self;
		std::shared_ptr<Window> m_window;
		std::shared_ptr<Resources> m_resources;

		std::shared_ptr<Sound> m_sound;
		// std::shared_ptr<Model> m_model;
		//std::shared_ptr<Keyboard> m_keyboard;
		
	};

}
