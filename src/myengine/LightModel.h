#pragma once
#include "Resource.h"
#include "Component.h"

#include <rend/rend.h>
#include <memory>

namespace myengine
{
	struct LightModel : Component, Resource
	{
		void onLoad();
		std::shared_ptr<rend::Model> getModel() { return m_model; }

	private:
		std::shared_ptr<rend::Model> m_model;
		std::shared_ptr<rend::Transform> m_transform;
	};
}