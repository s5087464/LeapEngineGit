#include "Model.h"
#include "Transform.h"
#include "Entity.h"
#include "Camera.h"

#include <iostream>
#include <string>
//#include <SDL2/SDL.h>

namespace myengine
{
	

	void Model::onLoad()
	{
		std::cout << "Loading model/n" << std::endl;
		// モデルのロード（一度だけ）
		m_model = std::make_shared<rend::Model>(std::string(getPath() + ".obj").c_str());
		
		// シェーダーの初期化（一度だけ）
		//m_shader = std::make_shared<rend::ModelShader>();
		
		// モデルとシェーダーの関連付け
		//m_shader->model(*m_model);

		// モデルの位置を原点に設定
		/*glm::mat4 model;
		model = glm::translate(model, glm::vec3(0, 0, -3.0));
		model = entity()->get_component<Transform>()->model();*/
	}

	/*
	void Model::on_render()
	{
		if (!m_model || !m_shader) return;

		

		//// ビュー行列の設定
		//m_shader->view(camera->get_view());

		// Projection setting
		rend::mat4 projection = rend::perspective(rend::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
		m_shader->projection(projection);

		rend::mat4 model(1.0f);
		model = rend::translate(model, rend::vec3(0, 0, -10));
		//model = rend::rotate(model, angle, rend::vec3(0, 0, 1));
		m_shader->model(model);

		// モデル行列の設定
		//m_transform = entity()->get_component<Transform>();
		//if (m_transform)
		//{
		//	// モデルを少し後ろに配置
		//	rend::mat4 model = rend::translate(rend::mat4(1.0f), rend::vec3(0.0f, 0.0f, -3.0f));
		//	model = m_transform->model();
		//	m_shader->model(model);
		//}

		// シェーダーの設定
		m_shader->depth_test(true);
		m_shader->lighting(true);
		m_shader->textures(false);

		// 描画
		m_shader->render();
	}
	*/

	//void Model::Model_Renderer(const std::string& _path)
	//{
	//	std::cout << "Model_Renderer/n" << std::endl;

	//	rend::Model model(_path.c_str());
	//	rend::ModelShader modelshader;
	//	modelshader.model(model);

	//	rend::Shader shader;
	//	rend::mat4 projection(rend::perspective(rend::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f));
	//	shader.uniform("u_Projection", projection);
	//	modelshader.projection(projection);

	//	rend::mat4 modelmatrix(1.0f);
	//	
	//	//modelshader.model(modelmatrix);

	//	auto transform = entity()->get_component<Transform>();
	//	if (transform) {
	//		modelmatrix = transform->model();
	//	}

	//	//model = entity()->get_component<Transform>()->model();

	//	shader.render();
	//	modelshader.render();

	//	m_shader->render();
	//}

	
}

		//float angle = 0;
		//modelmatrix = rend::translate(modelmatrix, rend::vec3(0, 0, -10));
		//modelmatrix = rend::rotate(modelmatrix, angle, rend::vec3(0, 0, 1));
		//angle -= 0.01f;

/*m_shader.attribute("a_Position", *m_mesh.positions());
		m_shader.attribute("a_TexCoord", *m_mesh.texcoords());
		m_shader.uniform("u_Projection", rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		model = glm::translate(model, glm::vec3(0, 0, -3.0));
		model = entity()->get_component<Transform>()->model();
		m_shader.uniform("u_Model", model);
		m_shader.render();*/


		//rend::Model curuthers(std::string model_string);
			// Load data required for displaying model
				//curuthers(std::string(getPath() + ".obj").c_str());
				// modelshader.model(curuthers);