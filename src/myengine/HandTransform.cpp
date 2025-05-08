#include "HandTransform.h"
#include "LeapInitialize.h"
#include <iostream>
#include <rend/glm/gtx/euler_angles.hpp>

namespace myengine
{
	void HandTransform::on_tick()
	{
		// m_position = glm::vec3(0, 0, -10);
		m_scale = glm::vec3(1, 1, 1);
		
		// LeapInitializeコンポーネントを取得
		//m_leap = entity()->get_component<LeapInitialize>();
		
		LEAP_TRACKING_EVENT* frame = GetFrame();
		if (frame && (frame->tracking_frame_id > lastFrameID)) {
			lastFrameID = frame->tracking_frame_id;
			printf("Frame %lli with %i hands.\n", (long long int)frame->tracking_frame_id, frame->nHands);
			for (uint32_t h = 0; h < frame->nHands; h++) {
				LEAP_HAND* hand = &frame->pHands[h];
				printf("    Hand id %i is a %s hand with position (%f, %f, %f).\n",
					hand->id,
					(hand->type == eLeapHandType_Left ? "left" : "right"),
					hand->palm.position.x,
					hand->palm.position.y,
					hand->palm.position.z);
				m_position = glm::vec3(
					hand->palm.position.x * 0.01f,
					hand->palm.position.y * 0.01f - 2.0,
					hand->palm.position.z * 0.01f);
			}
		}
	}

	//

	glm::mat4 HandTransform::model()
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


//// コールバックの設定
//ConnectionCallbacks.on_frame = [this](const LEAP_TRACKING_EVENT* tracking_event) {
//	if (tracking_event->nHands > 0)
//	{
//		const LEAP_HAND* hand = &tracking_event->pHands[0];
//		updateHandTransform(hand);
//	}
//};

//void HandTransform::updateHandTransform(const LEAP_HAND* hand)
//{
//	// 手のひらの位置を更新
//	m_position = glm::vec3(
//		hand->palm.position.x * 0.001f,  // mmからmに変換
//		hand->palm.position.y * 0.001f,
//		hand->palm.position.z * 0.001f
//	);

//	// 手のひらの向きから回転を計算
//	glm::vec3 normal(hand->palm.normal.x, hand->palm.normal.y, hand->palm.normal.z);
//	glm::vec3 direction(hand->palm.direction.x, hand->palm.direction.y, hand->palm.direction.z);

//	// 法線ベクトルと方向ベクトルから回転行列を計算
//	glm::mat4 rotationMatrix = glm::lookAt(
//		glm::vec3(0.0f),  // 原点
//		direction,        // 方向
//		normal           // 上方向
//	);

//	// 回転行列からオイラー角を取得
//	glm::vec3 eulerAngles = glm::eulerAngles(glm::quat_cast(rotationMatrix));
//	m_rotation = glm::degrees(eulerAngles);  // ラジアンから度に変換
//}