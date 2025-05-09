#include "LightModel.h"

#include <iostream>
#include <string>

namespace myengine
{
	void LightModel::onLoad()
	{
		std::cout << "Loading model/n" << std::endl;
		// Model Load(once)
		m_model = std::make_shared<rend::Model>(std::string(getPath() + ".obj").c_str());
	}
}