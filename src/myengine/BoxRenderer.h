#pragma once
#include <memory>
#include "Component.h"
#include "Texture.h"
#include <iostream>
#include <rend/rend.h>
#include "BoxModel.h"

namespace myengine
{
	struct BoxRenderer : Component
	{
		void on_initialize();
		void on_render();

		std::shared_ptr<BoxModel> getModel() { return m_model; }
		void setModel(std::shared_ptr<BoxModel> _model) { m_model = _model; }

	private:
		rend::Mesh m_mesh;
		rend::ModelShader m_shader;
		std::shared_ptr<BoxModel> m_model;
	};
}

