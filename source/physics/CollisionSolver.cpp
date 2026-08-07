#include <physics/Collider.h>
#include <physics/CollisionSolver.h>
#include <math/vec2.h>
#include <physics/RigidBody.h>
#include <vector>

using namespace PB_Physics;

Vec2 angularVelocityCrossRadius(float w, const Vec2& r)
{
	return Vec2(-w * r.y, w * r.x);
}

float cross(const Vec2& a, const Vec2& b)
{
	return a.x * b.y - a.y * b.x;
}

void PB_Physics::CollisionSolver::solveCollision(Collision& collision)
{
	RigidBody* a = collision.bodyA;
	RigidBody* b = collision.bodyB;




	Vec2 ra = collision.contactPoint - a->position;
	Vec2 rb = collision.contactPoint - b->position;

	Vec2 velocityA =
		a->velocity +
		angularVelocityCrossRadius(a->angularVelocity, ra);

	Vec2 velocityB =
		b->velocity +
		angularVelocityCrossRadius(b->angularVelocity, rb);

	//b->position.x += 1e-4f;


	float invMassA = 1.0f / a->mass;
	float invMassB = 1.0f / b->mass;

	Vec2 correction =
		collision.normal *
		(collision.penetration / (invMassA + invMassB));

	a->position = a->position - correction * invMassA;
	b->position = b->position + correction * invMassB;

	Vec2 relativeVelocity = velocityB - velocityA;

	float velocityAlongNormal = relativeVelocity.dot(collision.normal);

	if (velocityAlongNormal > 0)
		return;

	float j = -(1.0f + 0) * velocityAlongNormal;


	float raCrossN = cross(ra, collision.normal);
	float rbCrossN = cross(rb, collision.normal);

	float denominator =
		(1.0f / a->mass) +
		(1.0f / b->mass) +
		(raCrossN * raCrossN) / a->inertia +
		(rbCrossN * rbCrossN) / b->inertia;

	j = j / denominator;



	Vec2 impulse = collision.normal * j;

	a->velocity = a->velocity - (impulse / a->mass);
	b->velocity = b->velocity + (impulse / b->mass);

	a->angularVelocity -= cross(ra, impulse) / a->inertia;
	b->angularVelocity += cross(rb, impulse) / b->inertia;
}

void PB_Physics::CollisionSolver::solveCollisions(std::vector<Collision>& collisions)
{
	for (PB_Physics::Collision& collision : collisions) {
		PB_Physics::CollisionSolver::solveCollision(collision);
	}
}