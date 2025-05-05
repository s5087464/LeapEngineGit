#include <memory>
#include "Component.h"
#include "Texture.h"
#include <iostream>
#include <rend/rend.h>



namespace myengine
{
	struct TriangleRenderer : Component
	{
		void on_initialize();
		void on_render();

		

	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;
		
		//std::shared_ptr <Model> GetMesh() { return m_model; }
		//void SetMesh(std::shared_ptr<Texture> _texture) { m_texture = _texture; }
	};
}