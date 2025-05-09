#include "LightRenderer.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	void LightRenderer::on_initialize()
	{
		// Model Initialize
		if (!m_model)
		{
			std::cout << "Warning: Model not set in LightRenderer" << std::endl;
		}
	}

	void LightRenderer::on_render()
	{
		if (!m_model) {
			std::cout << "NO MODEL DATA" << std::endl;
			return;
		}

		// Associate model and shader
		try {
			// get Model data
			auto rendModel = m_model->getModel();
			if (!rendModel) {
				std::cout << "Error: Failed to get rend::LightModel" << std::endl;
				return;
			}
			m_shader.model(*rendModel);
		}
		catch (const std::exception& e) {
			std::cout << "Error setting model to shader: " << e.what() << std::endl;
			return;
		}

		// Projection matrix
		m_shader.projection(rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));

		// view matrix
		glm::mat4 view = glm::lookAt(
			glm::vec3(0.0f, 2.0f, 8.0f),  // ƒJƒƒ‰ˆÊ’u
			glm::vec3(0.0f, 0.0f, 0.0f),  // ’Ž‹“_
			glm::vec3(0.0f, 10.0f, 0.0f)   // ã•ûŒü
		);
		m_shader.view(view);

		// Model matrix
		glm::mat4 model = entity()->get_component<Transform>()->model();
		m_shader.model(model);

		// shader setting
		m_shader.depth_test(true);  
		m_shader.lighting(true);    
		m_shader.textures(true);    
		m_shader.color(glm::vec4(1.0));

		// Model rendering
		m_shader.render();
		std::cout << "LightRenderer::on_render" << std::endl;
	}
}