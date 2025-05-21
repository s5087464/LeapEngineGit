#include "Collision.h"
#include "Entity.h"
#include <random>

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
			
			// random generate
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<float> dis(-2.8f, 2.8f);  // random -5 to 5

			// random transform
			auto transformA = entity()->get_component<TransformA>();
			if (transformA)
			{
				glm::vec3 newPos(dis(gen), dis(gen)+0.5, dis(gen));
				transformA->set_position(newPos);
			}
		}
	}
}
