#pragma once
#ifndef LEAP_INITIALIZE_H
#define LEAP_INITIALIZE_H

#include "LeapC.h"
#include "leap/ExampleConnection.h"
#include "Component.h"
#include <memory>

namespace myengine
{
	struct LeapInitialize : Component
	{
		// void on_initialize();
		static void OnConnect();
		static void OnDevice();

		// void on_destroy();
		bool is_connected() const { return m_is_connected; }
		LEAP_CONNECTION* get_connection() const { return connectionHandle; }

	private:
		LEAP_CONNECTION* connectionHandle;
		bool m_is_connected;
	};
}

#endif // LEAP_INITIALIZE_H 