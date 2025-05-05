#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "rend/ModelShader.h"

namespace myengine
{
	void ModelRenderer::on_render()
	{
		if (!m_model) return;
		
		// モデル行列の設定
		glm::mat4 model = entity()->get_component<Transform>()->model();
		m_shader.model(model);

		// プロジェクション行列の設定
		m_shader.projection(rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));

		// ビュー行列の設定（カメラ位置を設定）
		glm::mat4 view = glm::lookAt(
			glm::vec3(0.0f, 0.0f, 3.0f),  // カメラ位置
			glm::vec3(0.0f, 0.0f, 0.0f),  // 注視点
			glm::vec3(0.0f, 1.0f, 0.0f)   // 上方向
		);
		m_shader.view(view);

		// シェーダーの設定
		m_shader.depth_test(true);
		m_shader.lighting(true);
		m_shader.textures(true);

		// モデルの描画
		m_shader.render();
	}

	void ModelRenderer::on_initialize()
	{
		// m_shader = std::make_shared<rend::ModelShader>();
	}
}



//glm::mat4 model(1.0f);
//// model  = glm::translate(model, glm::vec3(0, 0, -10));
//model entity()->getComponent<Transform>()->model();

// m_shader->uniform("u_Model", model)
// 
// 
// m_shader.uniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0.0f, 0.0f, -3.0f));