/*
Copyright (c) 2015, Giovanni Petrantoni
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef PHYSICSLAYER_EXPORTS
#define PHYSICSLAYER_API __declspec(dllexport)
#else
#define PHYSICSLAYER_API __declspec(dllimport)
#endif

#include <vector>

namespace PhysicsLayer
{
	class ColliderShape;
	class Matrix;
	class Collision;
	class Simulation;
	class Vector3;
	enum RigidbodyTypes;
	class Constraint;

	// This class is exported from the PhysicsLayer.dll
	class PHYSICSLAYER_API CPhysicsLayer 
	{
	public:
		CPhysicsLayer(void);
		// TODO: add your methods here.
	};

	class PHYSICSLAYER_API Collider
	{
	public:
		explicit Collider(ColliderShape* shape);
		virtual ~Collider();

		void SetEnabled(bool enabled);
		bool GetEnabled();

		void SetCanSleep(bool canSleep);
		bool GetCanSleep();

		bool GetIsActive();
		void Activate(bool forceActivation = true);

		void SetRestitution(float restitution);
		float GetRestitution();

		void SetFriction(float friction);
		float GetFriction();

		void SetRollingFriction(float rollingFriction);
		float GetRollingFriction();

		void SetCcdMotionThreshold(float t);
		float GetCcdMotionThreshold();

		void SetIsTrigger(bool t);
		bool GetIsTrigger();

		void SetPhysicsWorldTransform(const Matrix& m);
		void GetPhysicsWorldTransform(Matrix* m);

		virtual void SetColliderShape(ColliderShape* shape);
		virtual ColliderShape* GetColliderShape();

		void SetContactsAlwaysValid(bool c);
		bool GetContactsAlwaysValid();

		std::vector<Collision*> GetCollisions(); // ????

		Simulation* GetSimulation();
	};

	class PHYSICSLAYER_API Rigidbody : public Collider
	{
	public:
		explicit Rigidbody(ColliderShape* shape);
		virtual ~Rigidbody();

		void SetMass(float m);
		float GetMass();

		virtual void SetColliderShape(ColliderShape* s) override;
		virtual ColliderShape* GetColliderShape() override;

		void SetAngularDamping(float d);
		float GetAngularDamping();

		void SetLinearDamping(float d);
		float GetLinearDamping();

		void SetGravity(const Vector3& g);
		void GetGravity(Vector3* g);

		void SetOverrideGravity(bool o);
		bool GetOverrideGravity();

		void SetTotalTorque(const Vector3& t);
		void GetTotalTorque(Vector3* t);

		void ApplyImpulse(const Vector3& i);
		void ApplyImpulse(const Vector3& i, const Vector3& localOffset);

		void ApplyForce(const Vector3& i);
		void ApplyForce(const Vector3& i, const Vector3& localOffset);

		void ApplyTorque(const Vector3& t);

		void ApplyTorqueImpulse(const Vector3& t);

		void SetAngularVelocity(const Vector3& v);
		void GetAngularVelocity(Vector3* v);

		void SetLinearVelocity(const Vector3& v);
		void GetLinearVelocity(Vector3* v);

		void GetTotalForce(Vector3* f);

		void SetAngularFactor(const Vector3& v);
		void GetAngularFactor(Vector3* v);

		void SetLinearFactor(const Vector3& v);
		void GetLinearFactor(Vector3* v);

		void SetType(RigidbodyTypes type);
		RigidbodyTypes GetType();

		std::vector<Constraint*> GetLinkedConstraints();
	};
};

extern PHYSICSLAYER_API int nPhysicsLayer;

PHYSICSLAYER_API int fnPhysicsLayer(void);
