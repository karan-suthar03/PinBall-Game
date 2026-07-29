#ifndef BOX_H
#define BOX_H

#include <physics/RigidBody.h>
#include <physics/BoxCollider.h>
#include "core/Entity.h"
#include <graphics/BoxDrawable.h>

class Box : public Entity {
public:
	Box(float width, float height) : width(width), height(height), boxCollider(width, height) {
		rigidBody.collider = &boxCollider;

		collider = &boxCollider;
		body = &rigidBody;
		drawable = &boxDrawable;
	}

	Box(const Box& other) = delete;
	Box& operator=(const Box& other) = delete;

	float width;
	float height;

	PB_Physics::BoxCollider boxCollider;
	PB_Physics::RigidBody rigidBody;
	PB_Graphics::BoxDrawable boxDrawable;
};

#endif // BOX_H