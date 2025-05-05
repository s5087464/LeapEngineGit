#include "Resource.h"

namespace myengine
{
	std::string Resource::getPath() const
	{
		return m_path;
	}

	void Resource::load()
	{
		onLoad();
	}
}