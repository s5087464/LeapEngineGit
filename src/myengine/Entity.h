#include <memory>
#include <vector>

namespace myengine
{
	struct Core;
	struct Component;

	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> add_component()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->on_initialize();
			m_components.push_back(rtn);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> get_component()
		{
			for (size_t ci = 0; ci < m_components.size(); ++ci)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components.at(ci));

				if (rtn) return rtn;
			}
			throw std::runtime_error("failed to find component");
		}

	private:
		friend struct myengine::Core;

		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
		std::vector< std::shared_ptr<Component> > m_components;

		void tick();
		void render();
	};
}