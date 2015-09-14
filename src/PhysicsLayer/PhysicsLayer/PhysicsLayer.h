// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PHYSICSLAYER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PHYSICSLAYER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
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
