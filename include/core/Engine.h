#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include "Entity.h"
#include "../physics/PhysicsWorld.h"
#include <math/vec2.h>

class Engine {
private:
	std::vector<Entity*> entities;

	PB_Physics::PhysicsWorld physicsWorld;

public: 
	void update(float dt);

	void render();

	//void run();

	void addEntity(Entity entity);

	void addBoxAtPosition(const Vec2& position);

	void addBallAtPosition(const Vec2& position);

	int num_of_entities() {
		return entities.size();
	}
};

#endif // ENGINE_H