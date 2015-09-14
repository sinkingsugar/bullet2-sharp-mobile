// PhysicsLayer.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PhysicsLayer.h"


// This is an example of an exported variable
PHYSICSLAYER_API int nPhysicsLayer=0;

// This is an example of an exported function.
PhysicsLayer::Collider::Collider(ColliderShape* shape)
{
}

PhysicsLayer::Collider::~Collider()
{
}

void PhysicsLayer::Collider::SetEnabled(bool enabled)
{
}

bool PhysicsLayer::Collider::GetEnabled()
{
	return false;
}

void PhysicsLayer::Collider::SetCanSleep(bool canSleep)
{
}

bool PhysicsLayer::Collider::GetCanSleep()
{
	return false;
}

bool PhysicsLayer::Collider::GetIsActive()
{
	return false;
}

void PhysicsLayer::Collider::Activate(bool forceActivation)
{
}

void PhysicsLayer::Collider::SetRestitution(float restitution)
{
}

float PhysicsLayer::Collider::GetRestitution()
{
	return 0;
}

void PhysicsLayer::Collider::SetFriction(float friction)
{
}

float PhysicsLayer::Collider::GetFriction()
{
	return 0;
}

void PhysicsLayer::Collider::SetRollingFriction(float rollingFriction)
{
}

float PhysicsLayer::Collider::GetRollingFriction()
{
	return 0;
}

void PhysicsLayer::Collider::SetCcdMotionThreshold(float t)
{
}

float PhysicsLayer::Collider::GetCcdMotionThreshold()
{
	return 0;
}

void PhysicsLayer::Collider::SetIsTrigger(bool t)
{
}

bool PhysicsLayer::Collider::GetIsTrigger()
{
	return false;
}

void PhysicsLayer::Collider::SetPhysicsWorldTransform(const Matrix& m)
{
}

void PhysicsLayer::Collider::GetPhysicsWorldTransform(Matrix* m)
{
}

void PhysicsLayer::Collider::SetColliderShape(ColliderShape* shape)
{
}

PhysicsLayer::ColliderShape* PhysicsLayer::Collider::GetColliderShape()
{
	return nullptr;
}

void PhysicsLayer::Collider::SetContactsAlwaysValid(bool c)
{
}

bool PhysicsLayer::Collider::GetContactsAlwaysValid()
{
	return false;
}

std::vector<PhysicsLayer::Collision*> PhysicsLayer::Collider::GetCollisions()
{
	return {};
}

PhysicsLayer::Simulation* PhysicsLayer::Collider::GetSimulation()
{
	return nullptr;
}

PhysicsLayer::Rigidbody::Rigidbody(ColliderShape* shape): Collider(shape)
{
}

PhysicsLayer::Rigidbody::~Rigidbody()
{
}

void PhysicsLayer::Rigidbody::SetMass(float m)
{
}

float PhysicsLayer::Rigidbody::GetMass()
{
	return 0;
}

void PhysicsLayer::Rigidbody::SetColliderShape(ColliderShape* s)
{
}

PhysicsLayer::ColliderShape* PhysicsLayer::Rigidbody::GetColliderShape()
{
	return nullptr;
}

void PhysicsLayer::Rigidbody::SetAngularDamping(float d)
{
}

float PhysicsLayer::Rigidbody::GetAngularDamping()
{
	return 0;
}

void PhysicsLayer::Rigidbody::SetLinearDamping(float d)
{
}

float PhysicsLayer::Rigidbody::GetLinearDamping()
{
	return 0;
}

void PhysicsLayer::Rigidbody::SetGravity(const Vector3& g)
{
}

void PhysicsLayer::Rigidbody::GetGravity(Vector3* g)
{
}

void PhysicsLayer::Rigidbody::SetOverrideGravity(bool o)
{
}

bool PhysicsLayer::Rigidbody::GetOverrideGravity()
{
	return false;
}

void PhysicsLayer::Rigidbody::SetTotalTorque(const Vector3& t)
{
}

void PhysicsLayer::Rigidbody::GetTotalTorque(Vector3* t)
{
}

void PhysicsLayer::Rigidbody::ApplyImpulse(const Vector3& i)
{
}

void PhysicsLayer::Rigidbody::ApplyImpulse(const Vector3& i, const Vector3& localOffset)
{
}

void PhysicsLayer::Rigidbody::ApplyForce(const Vector3& i)
{
}

void PhysicsLayer::Rigidbody::ApplyForce(const Vector3& i, const Vector3& localOffset)
{
}

void PhysicsLayer::Rigidbody::ApplyTorque(const Vector3& t)
{
}

void PhysicsLayer::Rigidbody::ApplyTorqueImpulse(const Vector3& t)
{
}

void PhysicsLayer::Rigidbody::SetAngularVelocity(const Vector3& v)
{
}

void PhysicsLayer::Rigidbody::GetAngularVelocity(Vector3* v)
{
}

void PhysicsLayer::Rigidbody::SetLinearVelocity(const Vector3& v)
{
}

void PhysicsLayer::Rigidbody::GetLinearVelocity(Vector3* v)
{
}

void PhysicsLayer::Rigidbody::GetTotalForce(Vector3* f)
{
}

void PhysicsLayer::Rigidbody::SetAngularFactor(const Vector3& v)
{
}

void PhysicsLayer::Rigidbody::GetAngularFactor(Vector3* v)
{
}

void PhysicsLayer::Rigidbody::SetLinearFactor(const Vector3& v)
{
}

void PhysicsLayer::Rigidbody::GetLinearFactor(Vector3* v)
{
}

void PhysicsLayer::Rigidbody::SetType(RigidbodyTypes type)
{
}

PhysicsLayer::RigidbodyTypes PhysicsLayer::Rigidbody::GetType()
{
	return {};
}

std::vector<PhysicsLayer::Constraint*> PhysicsLayer::Rigidbody::GetLinkedConstraints()
{
	return {};
}

PHYSICSLAYER_API int fnPhysicsLayer(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see PhysicsLayer.h for the class definition
PhysicsLayer::CPhysicsLayer::CPhysicsLayer()
{
    return;
}
