#pragma once
#ifndef TRANSFORM_H
#endif TRANSFORM_H

#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	struct Transform : Component
	{
		void on_initialize();
		rend::mat4 model();
		// const rend::vec3& position() const { return m_position; }
		// const rend::vec3& rotation() const { return m_rotation; }

	private:
		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;

		rend::vec3 m_model;
	};
}
