#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"


namespace myengine
{
	void TriangleRenderer::on_render()
	{
		printf("Rendering Model\n");
		
		glm::mat4 model(1.0f);

		m_shader.attribute("a_Position", *m_mesh.positions());
		m_shader.attribute("a_TexCoord", *m_mesh.texcoords());
		m_shader.uniform("u_Projection", rend::perspective(45.0f, 1.0f, 0.1f, 100.0f));
		model = glm::translate(model, glm::vec3(0, 0, -3.0));
		model = entity()->get_component<Transform>()->model();
		m_shader.uniform("u_Model", model);
		m_shader.render();
	}

	void TriangleRenderer::on_initialize()
	{
		m_mesh = rend::Mesh(rend::TRIANGLE_MESH);
	}
}



//glm::mat4 model(1.0f);
//// model  = glm::translate(model, glm::vec3(0, 0, -10));
//model entity()->getComponent<Transform>()->model();

// m_shader->uniform("u_Model", model)
// 
// 
// m_shader.uniform("u_Model", rend::translate(rend::mat4(1.0f), rend::vec3(0.0f, 0.0f, -3.0f));