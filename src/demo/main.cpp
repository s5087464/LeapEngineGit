#include <myengine/myengine.h>

#include <iostream>

using namespace myengine;

struct Player : Component
{
	void on_initialize()
	{
		printf("Player::initialize\n");
	}

	void on_tick()
	{
		printf("Player::tick\n");
	}
};

struct Hand : Component
{
	std::shared_ptr<Model> model;

	void on_initialize()
	{
		printf("Hand::initialize\n");
	}
	
	void on_tick()
	{
		printf("Hand::tick\n");
	}
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	// Create a player entity
	std::shared_ptr <Entity> entity = core->add_entity();
	// Create a hand entity
	std::shared_ptr <Entity> handEntity = core->add_entity();

	// Add a player component to the player entity
	std::shared_ptr <Player> player = entity->add_component<Player>();
	// Add a triangle renderer component to the player entity
	std::shared_ptr <TriangleRenderer> tr = entity->add_component<TriangleRenderer>();
	// Add a hand component to the hand entity
	std::shared_ptr <Hand> hand = handEntity->add_component<Hand>();

	//std::shared_ptr <Model> model = handEntity->add_component<Model>();

	//entity->get_component<Transform>()->set_position(glm::vec3(10, 40, 3));


	// Audio
	std::shared_ptr <Sound> sound = core->resources()->load<Sound>("sounds/dixie_horn");

	// Model
	std::cout << "Loading curuthers" << std::endl;
	std::shared_ptr <Model> cruthers = core->resources()->load<Model>("models/curuthers/curuthers");
	std::cout << "Loading palm" << std::endl;
	//std::shared_ptr <Model> palm = core->resources()->load<Model>("models/hand/palm");
	std::shared_ptr<ModelRenderer> mr = entity->add_component<ModelRenderer>();
	mr->setModel(cruthers);

	// Texture
	std::shared_ptr <Texture> texture = core->resources()->load<Texture>("textures/cat");
	//tr->SetTexture(texture);

	core->run();

	return 0;
}
