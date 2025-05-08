#pragma once
#ifndef TRANSFORM_H
#endif TRANSFORM_H

#include "LeapC.h"
#include "leap/ExampleConnection.h"
#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	struct LeapInitialize;  // 前方宣言

	struct HandTransform : Component
	{
		void on_tick();
		rend::mat4 model();
		const rend::vec3& position() const { return m_position; }
		const rend::vec3& rotation() const { return m_rotation; }
		// const rend::vec3& scale() const { return m_scale; }

		

	private:
		int64_t lastFrameID;

		rend::vec3 m_position;
		rend::vec3 m_rotation;
		rend::vec3 m_scale;
		LEAP_CONNECTION* connectionHandle;
		std::shared_ptr<LeapInitialize> m_leap;
	};
}


//bool checkLeapConnection();
//void updateHandTransform(const LEAP_HAND* hand);