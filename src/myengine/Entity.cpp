#include "Entity.h"
#include "Component.h"

namespace myengine
{
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick();
		}
	}

	void Entity::render()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->render();
		}
	}

}
