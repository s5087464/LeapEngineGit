#pragma once

#include "Component.h"
#include "Transform.h"
#include <rend/rend.h>

namespace myengine
{
	struct Camera : Component
	{
		Camera();

		rend::mat4 get_projection(){ return m_projection; };
		rend::mat4 get_view(){ return rend::inverse(m_transform->model()); };
		Transform* m_transform;

	private:
		float m_fov;
		float m_aspect;
		float m_near;
		float m_far;
		
		rend::mat4 m_projection;
	};
}
