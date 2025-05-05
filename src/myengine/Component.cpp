#include "Component.h"

namespace myengine
{
	std::shared_ptr<Entity> Component::entity()
	{
		return m_entity.lock();
	}

	void Component::on_initialize() {};
	void Component::on_tick() {};
	void Component::tick()
	{
		on_tick();
	}

	void Component::on_render() {};
	void Component::render()
	{
		on_render();
	}
}