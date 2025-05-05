#include "Transform.h"

namespace myengine 
{
	void Transform::on_initialize()
	{
		m_position = glm::vec3(0, 0, -10);// remove me
		m_scale = glm::vec3(1, 1, 1);
	}
	glm::mat4 Transform::model()
	{
		glm::mat4 rtn(1.0f);		

		rtn = glm::translate(rtn, m_position);
		rtn = glm::rotate(rtn, glm::radians(m_rotation.x), glm::vec3(1, 0, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.y), glm::vec3(0, 1, 0));
		rtn = glm::rotate(rtn, glm::radians(m_rotation.z), glm::vec3(0, 0, 1));
		rtn = glm::scale(rtn, m_scale);

		return rtn;
	}

}
