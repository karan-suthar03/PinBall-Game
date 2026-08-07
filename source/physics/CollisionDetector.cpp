#include "physics/CollisionDetector.h"
#include "physics/CircleCollider.h"
#include "physics/BoxCollider.h"
#include <math/vec2.h>
#include <vector>
#include <physics/RigidBody.h>
#include <iostream>
#include <algorithm>
#include <cfloat>
#include <cstdlib>
#include <array>

using namespace PB_Physics;

bool CollisionDetector::checkCollision(RigidBody* a, RigidBody* b, Collision& collision) {

	if(a->collider->getType() == ColliderType::CIRCLE && b->collider->getType() == ColliderType::CIRCLE) {
		return checkCircleCircleCollision(a, b, collision);
	}

	if (a->collider->getType() == ColliderType::CIRCLE && b->collider->getType() == ColliderType::BOX) {
		return checkCircleBoxCollision(a, b, collision);
	}

	if (a->collider->getType() == ColliderType::BOX && b->collider->getType() == ColliderType::CIRCLE) {
		return checkCircleBoxCollision(b, a, collision);
	}

	if (a->collider->getType() == ColliderType::BOX && b->collider->getType() == ColliderType::BOX) {
		return checkBoxBoxCollision(a, b, collision);
	}

	return false;
}



void CollisionDetector::detectCollisions(const std::vector<RigidBody*>& bodies, std::vector<Collision>& collisions)
{
	for (size_t i = 0; i < bodies.size(); ++i) {
		for (size_t j = i + 1; j < bodies.size(); ++j) {
			Collision collision;

			if (CollisionDetector::checkCollision(bodies[i], bodies[j], collision)) {
				collisions.push_back(collision);
			}
		}
	}
}

bool CollisionDetector::checkCircleBoxCollision(RigidBody* a, RigidBody* b, Collision& collision)
{
	CircleCollider* circle = static_cast<CircleCollider*>(a->collider);
	BoxCollider* box = static_cast<BoxCollider*>(b->collider);

	std::array<Vec2, 2> BoxAABB = box->getAABB(b->position, b->rotation);

	if (a->position.x + circle->radius < BoxAABB[0].x ||
		a->position.x - circle->radius > BoxAABB[1].x ||
		a->position.y + circle->radius < BoxAABB[0].y ||
		a->position.y - circle->radius > BoxAABB[1].y)
	{
		return false;
	}


	Vec2 local = (a->position - b->position).rotate(-b->rotation);

	Vec2 closestPoint;
	closestPoint.x = std::max(-box->halfExtents.x, std::min(local.x, box->halfExtents.x));
	closestPoint.y = std::max(-box->halfExtents.y, std::min(local.y, box->halfExtents.y));

	Vec2 delta = local - closestPoint;
	float distanceSquared = delta.getDistanceSquared();

	if (distanceSquared > circle->radius * circle->radius)
		return false;

	collision.bodyA = a;
	collision.bodyB = b;
	collision.type = CollisionType::CIRCLE_BOX;

	if (distanceSquared == 0.0f)
	{
		float left = local.x + box->halfExtents.x;
		float right = box->halfExtents.x - local.x;
		float bottom = local.y + box->halfExtents.y;
		float top = box->halfExtents.y - local.y;

		float minDist = left;
		Vec2 normal(-1, 0);

		if (right < minDist)
		{
			minDist = right;
			normal = Vec2(1, 0);
		}

		if (bottom < minDist)
		{
			minDist = bottom;
			normal = Vec2(0, -1);
		}

		if (top < minDist)
		{
			minDist = top;
			normal = Vec2(0, 1);
		}

		collision.normal = normal.rotate(b->rotation);
		collision.penetration = circle->radius + minDist;
		collision.contactPoint =
			closestPoint.rotate(b->rotation) +
			b->position;

		return true;
	}

	float distance = std::sqrt(distanceSquared);

	collision.normal = (delta / distance).rotate(b->rotation);
	collision.normal = collision.normal * -1.0f;
	collision.penetration = circle->radius - distance;

	collision.contactPoint =
		closestPoint.rotate(b->rotation) +
		b->position;

	return true;
}


bool CollisionDetector::checkCircleCircleCollision(RigidBody* a, RigidBody* b, Collision& collision) {
	CircleCollider* ca =
		static_cast<CircleCollider*>(a->collider);

	CircleCollider* cb =
		static_cast<CircleCollider*>(b->collider);

	Vec2 delta = b->position - a->position;
	
	float distanceSqared = delta.getDistanceSquared();

	float temp = ca->radius + cb->radius;

	if (distanceSqared < temp*temp) {

		collision.bodyA = a;
		collision.bodyB = b;

		collision.normal = delta.normalize();

		collision.type = CollisionType::CIRCLE_CIRCLE;

		float distance = delta.length();
		collision.penetration = (ca->radius + cb->radius) - distance;

		collision.contactPoint = a->position + collision.normal * ca->radius;

		return true;
	}

	return false;
}

bool pointInsideBox(
	const Vec2& point,
	const BoxCollider* box,
	const RigidBody* body)
{
	Vec2 local = (point - body->position).rotate(-body->rotation);

	return
		std::abs(local.x) <= box->halfExtents.x &&
		std::abs(local.y) <= box->halfExtents.y;
}


bool CollisionDetector::checkBoxBoxCollision(
	RigidBody* a,
	RigidBody* b,
	Collision& collision)
{
	auto* boxA = static_cast<BoxCollider*>(a->collider);
	auto* boxB = static_cast<BoxCollider*>(b->collider);

	std::array<Vec2, 2> aabbA = boxA->getAABB(a->position, a->rotation);
	std::array<Vec2, 2> aabbB = boxB->getAABB(b->position, b->rotation);

	if (aabbA[1].x < aabbB[0].x ||
		aabbA[0].x > aabbB[1].x ||
		aabbA[1].y < aabbB[0].y ||
		aabbA[0].y > aabbB[1].y)
	{
		return false;
	}

	std::array<Vec2, 4> verticesA = boxA->getWorldVertices(a->position, a->rotation);
	std::array<Vec2, 4> verticesB = boxB->getWorldVertices(b->position, b->rotation);

	Vec2 axes[4];

	axes[0] = (verticesA[1] - verticesA[0]).perpendicular().normalize();
	axes[1] = (verticesA[3] - verticesA[0]).perpendicular().normalize();

	axes[2] = (verticesB[1] - verticesB[0]).perpendicular().normalize();
	axes[3] = (verticesB[3] - verticesB[0]).perpendicular().normalize();

	float smallestOverlap = FLT_MAX;
	Vec2 smallestAxis;

	for (int i = 0; i < 4; i++)
	{
		const Vec2& axis = axes[i];

		float minA = verticesA[0].dot(axis);
		float maxA = minA;

		for (int j = 1; j < 4; j++)
		{
			float projection = verticesA[j].dot(axis);

			if (projection < minA) minA = projection;
			if (projection > maxA) maxA = projection;
		}

		float minB = verticesB[0].dot(axis);
		float maxB = minB;

		for (int j = 1; j < 4; j++)
		{
			float projection = verticesB[j].dot(axis);

			if (projection < minB) minB = projection;
			if (projection > maxB) maxB = projection;
		}

		float overlap =
			std::min(maxA, maxB) -
			std::max(minA, minB);

		if (overlap <= 0.0f)
			return false;

		if (overlap < smallestOverlap)
		{
			smallestOverlap = overlap;
			smallestAxis = axis;
		}
	}

	Vec2 direction = b->position - a->position;

	if (direction.dot(smallestAxis) < 0.0f)
		smallestAxis = -smallestAxis;

	collision.bodyA = a;
	collision.bodyB = b;
	collision.normal = smallestAxis;
	collision.penetration = smallestOverlap;
	collision.type = CollisionType::BOX_BOX;

	std::vector<Vec2> contacts;

	for (const Vec2& vertex : verticesA)
	{
		if (pointInsideBox(vertex, boxB, b))
			contacts.push_back(vertex);
	}

	for (const Vec2& vertex : verticesB)
	{
		if (pointInsideBox(vertex, boxA, a))
			contacts.push_back(vertex);
	}

	if (!contacts.empty())
	{
		Vec2 average(0.0f, 0.0f);

		for (const Vec2& p : contacts)
			average = average + p;

		average =average/ static_cast<float>(contacts.size());

		collision.contactPoint = average;
	}
	else
	{
		collision.contactPoint = (a->position + b->position) * 0.5f;
	}

	return true;

}