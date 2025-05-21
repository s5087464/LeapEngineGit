#include "Collision.h"
#include "Entity.h"


namespace myengine
{
	Collision::Collision()
	{
	}

	bool Collision::CheckCollision()
	{
		auto transformA = entity()->get_component<TransformA>();
		auto handTransform = entity()->get_component<HandTransform>();

		// get position data from both transform
		glm::vec3 boxPos = transformA->position();
		glm::vec3 handPos = handTransform->position();

		// return by AABB detction
		return (boxPos.x - m_size.x / 2 <= handPos.x + m_size.x / 2 &&
			boxPos.x + m_size.x / 2 >= handPos.x - m_size.x / 2 &&
			boxPos.y - m_size.y / 2 <= handPos.y + m_size.y / 2 &&
			boxPos.y + m_size.y / 2 >= handPos.y - m_size.y / 2 &&
			boxPos.z - m_size.z / 2 <= handPos.z + m_size.z * 3/2 &&
			boxPos.z + m_size.z / 2 >= handPos.z - m_size.z * 3/2);
	}

	void Collision::on_tick()
	{
		// if collision is happened
		if (CheckCollision())
		{
			std::cout << "Collision detected!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
			auto lightRenderer = entity()->get_component<LightRenderer>();
			if (lightRenderer)
			{
				lightRenderer->color() = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			}
		}
		//else
		//{
		//	auto lightRenderer = entity()->get_component<LightRenderer>();
		//	if (lightRenderer)
		//	{
		//		lightRenderer->color() = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
		//	}
		//}
	}
}
