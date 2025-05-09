#include "Collision.h"
#include "Entity.h"
#include "HandTransform.h"
#include "TransformA.h"

namespace myengine
{
	//Collision::Collision()
	//{
	//}

	//bool Collision::CheckCollision(Collision* other)
	//{
	//	if (!other) return false;

	//	// Transformから位置を取得
	//	glm::vec3 pos1 = entity()->get_component<TransformA>()->position();
	//	glm::vec3 pos2 = other->entity()->get_component<HandTransform>()->position();

	//	// シンプルなAABB衝突判定
	//	return (pos1.x - m_size.x/2 <= pos2.x + other->m_size.x/2 &&
	//			pos1.x + m_size.x/2 >= pos2.x - other->m_size.x/2 &&
	//			pos1.y - m_size.y/2 <= pos2.y + other->m_size.y/2 &&
	//			pos1.y + m_size.y/2 >= pos2.y - other->m_size.y/2 &&
	//			pos1.z - m_size.z/2 <= pos2.z + other->m_size.z/2 &&
	//			pos1.z + m_size.z/2 >= pos2.z - other->m_size.z/2);
	//}
}
