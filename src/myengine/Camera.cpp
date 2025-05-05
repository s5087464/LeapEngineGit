#include "Camera.h"
#include "Transform.h"
#include "Entity.h"
#include <iostream>

namespace myengine
{
	Camera::Camera()
	{
		m_fov = 45.0f;
		m_aspect = 800.0f / 600.0f;
		m_near = 0.1f;
		m_far = 100.0f;
		m_transform = nullptr;
	}

	/*rend::mat4 Camera::get_projection()
	{
		m_projection = rend::perspective(rend::radians(m_fov), m_aspect, m_near, m_far);
		return m_projection;
	}*/

	//rend::mat4 Camera::get_view()
	//{
	//	if (!m_transform)
	//	{
	//		m_transform = entity()->get_component<Transform>();
	//		if (m_transform)
	//		{
	//			// カメラを原点から少し後ろに配置
	//			m_transform->position = rend::vec3(0, 0, -5);
	//		}
	//	}
	//	return rend::inverse(m_transform->model());
	//}
} 