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

struct Light : Component
{
	//std::shared_ptr<Model> model;

	void on_initialize()
	{
		printf("Light::initialize\n");
	}
	
	void on_tick()
	{
		printf("Light::tick\n");
	}
};

struct Box : Component
{
	void on_initialize()
	{
		printf("Box::initialize\n");
	}

	void on_tick()
	{
		printf("Box::tick\n");
	}
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	//////////////////////////////////////////////////////////////////
	// Player
	//////////////////////////////////////////////////////////////////
	// Create a player entity
	std::shared_ptr <Entity> entity = core->add_entity();
	// Add a player component to the player entity
	std::shared_ptr <Player> player = entity->add_component<Player>();
	// Model
	// std::cout << "Loading curuthers" << std::endl;
	// std::shared_ptr <Model> cruthers = core->resources()->load<Model>("models/curuthers/curuthers");
	//mr->setModel(cruthers);
	std::cout << "Loading palm" << std::endl;
	std::shared_ptr <Model> palm = core->resources()->load<Model>("models/hand/palm");
	std::shared_ptr<ModelRenderer> mr = entity->add_component<ModelRenderer>();
	mr->setModel(palm);
	// Leap
	std::shared_ptr<HandTransform> ht = entity->add_component<HandTransform>();
	ht->on_tick();
	// Collision
	// std::shared_ptr<Collision> co = entity->add_component<Collision>();
	

	//////////////////////////////////////////////////////////////////
	// Lighting
	//////////////////////////////////////////////////////////////////
	// Create a hand entity
	std::shared_ptr <Entity> lightEntity = core->add_entity();
	// Add a hand component to the hand entity
	std::shared_ptr <Light> light = lightEntity->add_component<Light>();
	// Model
	std::cout << "Loading light" << std::endl;
	std::shared_ptr <LightModel> lighting = core->resources()->load<LightModel>("models/switch/light");
	std::shared_ptr<LightRenderer> lr = lightEntity->add_component<LightRenderer>();
	lr->setModel(lighting);


	//////////////////////////////////////////////////////////////////
	// SwitchBox
	//////////////////////////////////////////////////////////////////
	// Create a hand entity
	std::shared_ptr <Entity> boxEntity = core->add_entity();
	// Add a hand component to the hand entity
	std::shared_ptr <Box> box = boxEntity->add_component<Box>();
	// Model
	std::cout << "Loading Box" << std::endl;
	std::shared_ptr <BoxModel> switchBox = core->resources()->load<BoxModel>("models/switch/SwitchA");
	std::shared_ptr<BoxRenderer> br = boxEntity->add_component<BoxRenderer>();
	br->setModel(switchBox);
	std::shared_ptr<TransformA> ta = entity->add_component<TransformA>();


	
	// Add a triangle renderer component to the player entity
	// std::shared_ptr <TriangleRenderer> tr = entity->add_component<TriangleRenderer>();
	

	//std::shared_ptr <Model> model = handEntity->add_component<Model>();

	//entity->get_component<Transform>()->set_position(glm::vec3(10, 40, 3));


	// Audio
	std::shared_ptr <Sound> sound = core->resources()->load<Sound>("sounds/gamestart");

	
	

	// Texture
	// std::shared_ptr <Texture> texture = core->resources()->load<Texture>("textures/cat");
	//tr->SetTexture(texture);

	core->run();

	return 0;
}
