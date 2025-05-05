#pragma once
#include "Resource.h"
#include <rend/rend.h>
#include <memory>

namespace myengine
{
	struct Texture : Resource
	{
		void onLoad();
	private:
		std::shared_ptr<rend::Texture> m_texture;
	};
}