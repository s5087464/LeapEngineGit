#pragma once

#include <string>

namespace myengine
{
	struct Resources;
	struct Resource
	{
		virtual void onLoad() = 0;
		std::string getPath() const;
	private:
		friend struct myengine::Resources;

		std::string m_path;
		void load();
	};


}