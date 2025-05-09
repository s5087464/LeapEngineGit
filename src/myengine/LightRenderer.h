#pragma once
#include <memory>
#include "Component.h"
#include "Texture.h"
#include <iostream>
#include <rend/rend.h>
#include "LightModel.h"

namespace myengine
{
	struct LightRenderer : Component
	{
		void on_initialize();
		void on_render();

		std::shared_ptr<LightModel> getModel() { return m_model; }
		void setModel(std::shared_ptr<LightModel> _model) { m_model = _model; }

	private:
		rend::Mesh m_mesh;
		rend::ModelShader m_shader;
		std::shared_ptr<LightModel> m_model;
	};
}

