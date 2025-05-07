#pragma once

#include <memory>
#include "Component.h"
#include "Texture.h"
#include <iostream>
#include <rend/rend.h>
#include "Model.h"

namespace myengine
{
	struct ModelRenderer : Component
	{
		void on_initialize();
		void on_render();

		std::shared_ptr<Model> getModel() { return m_model; }
		void setModel(std::shared_ptr<Model> _model) { m_model = _model; }

	private:
		rend::Mesh m_mesh;
		rend::ModelShader m_shader;
		std::shared_ptr<Model> m_model;
		
		//std::shared_ptr <Model> GetMesh() { return m_model; }
		//void SetMesh(std::shared_ptr<Texture> _texture) { m_texture = _texture; }
	};
}

