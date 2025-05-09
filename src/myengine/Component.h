#pragma once

#include <memory>

namespace myengine 
{
	struct Entity;
	//struct Core;

	struct Component
	{
		//friend struct Entity;

		virtual void on_initialize();
		virtual void on_tick();
		virtual void on_render();
		std::shared_ptr<Entity> entity();
		// std::shared_ptr<Entity> entity() const;

	private:
		friend struct myengine::Entity;
		std::weak_ptr<Entity> m_entity;

		void tick();
		void render();
	};
}