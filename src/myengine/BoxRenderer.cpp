#include "BoxRenderer.h"
#include "Entity.h"
#include "TransformA.h"

namespace myengine
{
	void BoxRenderer::on_initialize()
	{
		// Model Initialize
		if (!m_model)
		{
			std::cout << "Warning: Model not set in BoxRenderer" << std::endl;
		}
	}

	void BoxRenderer::on_render()
	{
		if (!m_model) {
			std::cout << "NO MODEL DATA" << std::endl;
			return;
		}

		// モデルとシェーダーの関連付け
		try {
			// get Model data
			auto rendModel = m_model->getModel();
			if (!rendModel) {
				std::cout << "Error: Failed to get rend::BoxModel" << std::endl;
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
			glm::vec3(0.0f, 2.0f, 8.0f),  // カメラ位置
			glm::vec3(0.0f, 0.0f, 0.0f),  // 注視点
			glm::vec3(0.0f, 10.0f, 0.0f)   // 上方向
		);
		m_shader.view(view);

		// Model matrix
		glm::mat4 model = entity()->get_component<TransformA>()->model();
		m_shader.model(model);

		// shader setting
		m_shader.depth_test(true);
		m_shader.lighting(true);
		m_shader.textures(true);
		m_shader.color(glm::vec4(1.0));

		// m_mesh.texcoords();

		// Model rendering
		m_shader.render();
		std::cout << "BoxRenderer::on_render" << std::endl;
	}
}