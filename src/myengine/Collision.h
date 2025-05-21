#pragma once
#include <memory>
#include <iostream>
#include "Component.h"
#include "HandTransform.h"
#include "TransformA.h"
#include "LightRenderer.h"
#include <rend/glm/glm.hpp>

namespace myengine
{
	struct Collision : Component
	{
		Collision();
		void on_tick();

		// collision size setter
		void SetSize(const glm::vec3& size) { m_size = size; }
		
		// Collision detect
		bool CheckCollision();

	private:
		glm::vec3 m_size = glm::vec3(1.0f);
		
		std::shared_ptr<TransformA> m_transformA;
		std::shared_ptr<HandTransform> m_handTransform;
		std::shared_ptr<LightRenderer> m_light;
	};
}