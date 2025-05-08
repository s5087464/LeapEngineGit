#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	void ModelRenderer::on_initialize()
	{
		//m_mesh = rend::Mesh(rend::TRIANGLE_MESH);
		// モデルの初期化
		if (!m_model)
		{
			std::cout << "Warning: Model not set in ModelRenderer" << std::endl;
		}
	}

	void ModelRenderer::on_render()
	{
		if (!m_model) { 
			std::cout << "NO MODEL DATA" << std::endl; 
			return; 
		}
		
		// モデルとシェーダーの関連付け
		try {
			// モデルデータの取得
			auto rendModel = m_model->getModel();
			if (!rendModel) {
				std::cout << "Error: Failed to get rend::Model" << std::endl;
				return;
			}
			m_shader.model(*rendModel);
		}
		catch (const std::exception& e) {
			std::cout << "Error setting model to shader: " << e.what() << std::endl;
			return;
		}

		// プロジェクション行列の設定
		m_shader.projection(rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));

		// ビュー行列の設定（カメラ位置を設定）
		glm::mat4 view = glm::lookAt(
			glm::vec3(0.0f, 0.0f, 5.0f),  // カメラ位置
			glm::vec3(0.0f, 0.0f, 0.0f),  // 注視点
			glm::vec3(0.0f, 10.0f, 0.0f)   // 上方向
		);
		m_shader.view(view);

		// モデル行列の設定
		glm::mat4 model = entity()->get_component<Transform>()->model();
		m_shader.model(model);

		// シェーダーの設定
		m_shader.depth_test(true);  // 深度テストを有効化
		m_shader.lighting(true);    // ライティングを有効化
		m_shader.textures(true);    // テクスチャを有効化

		// m_mesh.texcoords();

		// モデルの描画
		m_shader.render();
		std::cout << "ModelRenderer::on_render" << std::endl;
	}
}

//glm::mat4 model(1.0f);
//// model  = glm::translate(model, glm::vec3(0, 0, -10));
//model entity()->getComponent<Transform>()->model();

// m_shader->uniform("u_Model", model)
// 
// 
// m_shader.uniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0.0f, 0.0f, -3.0f));