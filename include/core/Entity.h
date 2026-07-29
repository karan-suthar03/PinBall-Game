#ifndef ENTITY_H
#define ENTITY_H

namespace PB_Physics
{
    class RigidBody;
    class Collider;
}

namespace PB_Graphics
{
    class Drawable;
}

class Entity {
public:
    PB_Physics::RigidBody* body = nullptr;
    PB_Physics::Collider* collider = nullptr;
	PB_Graphics::Drawable* drawable = nullptr;
};

#endif // ENTITY_H