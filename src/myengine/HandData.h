#include "LeapC.h"
#include "leap/ExampleConnection.h"
#include "Component.h"
#include <vector>
#include <iostream>

namespace myengine
{
	struct HandData : Component
	{
		void on_initialize();
		void on_update();

		
	};
}