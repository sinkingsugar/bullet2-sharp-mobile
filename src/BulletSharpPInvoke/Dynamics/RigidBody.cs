using SiliconStudio.Core.Mathematics;
using System;
using System.Runtime.InteropServices;
using System.Security;

namespace BulletSharp
{
    public enum RigidBodyFlags
	{
		None = 0,
		DisableWorldGravity = 1,
		EnableGyroscopicForce = 2
	}

	public class RigidBody : CollisionObject
	{
        //MotionState _motionState;

		internal RigidBody(IntPtr native)
			: base(native)
		{
		}

        /*
		public RigidBody(RigidBodyConstructionInfo constructionInfo)
			: base(btRigidBody_new(constructionInfo._native))
		{
            _motionState = constructionInfo._motionState;
		}
        */

		public RigidBody(float mass, SharpMotionState motionState, CollisionShape collisionShape, Vector3 localInertia)
			: base(btRigidBody_new2(mass, motionState._native, collisionShape._native, ref localInertia))
		{
            //_motionState = motionState;
		}

        /*
		public RigidBody(float mass, MotionState motionState, CollisionShape collisionShape)
			: base(btRigidBody_new3(mass, motionState._native, collisionShape._native))
		{
            _motionState = motionState;
		}
        */

		public void AddConstraintRef(TypedConstraint c)
		{
			btRigidBody_addConstraintRef(_native, c._native);
		}

		public void ApplyCentralForce(Vector3 force)
		{
			btRigidBody_applyCentralForce(_native, ref force);
		}

		public void ApplyCentralImpulse(Vector3 impulse)
		{
			btRigidBody_applyCentralImpulse(_native, ref impulse);
		}

		public void ApplyDamping(float timeStep)
		{
			btRigidBody_applyDamping(_native, timeStep);
		}

		public void ApplyForce(Vector3 force, Vector3 rel_pos)
		{
			btRigidBody_applyForce(_native, ref force, ref rel_pos);
		}

		public void ApplyGravity()
		{
			btRigidBody_applyGravity(_native);
		}

		public void ApplyImpulse(Vector3 impulse, Vector3 rel_pos)
		{
			btRigidBody_applyImpulse(_native, ref impulse, ref rel_pos);
		}

		public void ApplyTorque(Vector3 torque)
		{
			btRigidBody_applyTorque(_native, ref torque);
		}

		public void ApplyTorqueImpulse(Vector3 torque)
		{
			btRigidBody_applyTorqueImpulse(_native, ref torque);
		}

		public bool CheckCollideWithOverride(CollisionObject co)
		{
			return btRigidBody_checkCollideWithOverride(_native, co._native);
		}

		public void ClearForces()
		{
			btRigidBody_clearForces(_native);
		}

		public float ComputeAngularImpulseDenominator(Vector3 axis)
		{
			return btRigidBody_computeAngularImpulseDenominator(_native, ref axis);
		}

		public void ComputeGyroscopicForce(float maxGyroscopicForce)
		{
			btRigidBody_computeGyroscopicForce(_native, maxGyroscopicForce);
		}

		public float ComputeImpulseDenominator(Vector3 pos, Vector3 normal)
		{
			return btRigidBody_computeImpulseDenominator(_native, ref pos, ref normal);
		}

		public void GetAabb(out Vector3 aabbMin, out Vector3 aabbMax)
		{
            btRigidBody_getAabb(_native, out aabbMin, out aabbMax);
		}

		public TypedConstraint GetConstraintRef(int index)
		{
			return TypedConstraint.GetManaged(btRigidBody_getConstraintRef(_native, index));
		}

        public Vector3 GetVelocityInLocalPoint(Vector3 rel_pos)
        {
            Vector3 velocity;
            btRigidBody_getVelocityInLocalPoint(_native, ref rel_pos, out velocity);
            return velocity;
        }

		public void IntegrateVelocities(float step)
		{
			btRigidBody_integrateVelocities(_native, step);
		}

		public void PredictIntegratedTransform(float step, out Matrix predictedTransform)
		{
			btRigidBody_predictIntegratedTransform(_native, step, out predictedTransform);
		}

		public void ProceedToTransform(Matrix newTrans)
		{
			btRigidBody_proceedToTransform(_native, ref newTrans);
		}

		public void RemoveConstraintRef(TypedConstraint c)
		{
			btRigidBody_removeConstraintRef(_native, c._native);
		}

		public void SaveKinematicState(float step)
		{
			btRigidBody_saveKinematicState(_native, step);
		}

		public void SetDamping(float lin_damping, float ang_damping)
		{
			btRigidBody_setDamping(_native, lin_damping, ang_damping);
		}

		public void SetMassProps(float mass, Vector3 inertia)
		{
			btRigidBody_setMassProps(_native, mass, ref inertia);
		}

		public void SetNewBroadphaseProxy(BroadphaseProxy broadphaseProxy)
		{
			btRigidBody_setNewBroadphaseProxy(_native, broadphaseProxy._native);
		}

		public void SetSleepingThresholds(float linear, float angular)
		{
			btRigidBody_setSleepingThresholds(_native, linear, angular);
		}

		public void Translate(Vector3 v)
		{
			btRigidBody_translate(_native, ref v);
		}

		public RigidBody Upcast(CollisionObject colObj)
		{
            return RigidBody.GetManaged(btRigidBody_upcast(colObj._native)) as RigidBody;
		}

		public void UpdateDeactivation(float timeStep)
		{
			btRigidBody_updateDeactivation(_native, timeStep);
		}

		public void UpdateInertiaTensor()
		{
			btRigidBody_updateInertiaTensor(_native);
		}

		public bool WantsSleeping()
		{
			return btRigidBody_wantsSleeping(_native);
		}

		public float AngularDamping
		{
			get { return btRigidBody_getAngularDamping(_native); }
		}

		public Vector3 AngularFactor
		{
			get
			{
				Vector3 value;
				btRigidBody_getAngularFactor(_native, out value);
				return value;
			}
			set { btRigidBody_setAngularFactor(_native, ref value); }
		}

		public float AngularSleepingThreshold
		{
			get { return btRigidBody_getAngularSleepingThreshold(_native); }
		}

		public Vector3 AngularVelocity
		{
			get
			{
				Vector3 value;
				btRigidBody_getAngularVelocity(_native, out value);
				return value;
			}
			set { btRigidBody_setAngularVelocity(_native, ref value); }
		}

		public BroadphaseProxy BroadphaseProxy
		{
            get { return BroadphaseProxy.GetManaged(btRigidBody_getBroadphaseProxy(_native)); }
		}

		public Vector3 CenterOfMassPosition
		{
			get
			{
				Vector3 value;
				btRigidBody_getCenterOfMassPosition(_native, out value);
				return value;
			}
		}

		public Matrix CenterOfMassTransform
		{
			get
			{
				Matrix value;
				btRigidBody_getCenterOfMassTransform(_native, out value);
				return value;
			}
			set { btRigidBody_setCenterOfMassTransform(_native, ref value); }
		}

		public int ContactSolverType
		{
			get { return btRigidBody_getContactSolverType(_native); }
			set { btRigidBody_setContactSolverType(_native, value); }
		}

        public RigidBodyFlags Flags
		{
			get { return btRigidBody_getFlags(_native); }
			set { btRigidBody_setFlags(_native, value); }
		}

		public int FrictionSolverType
		{
			get { return btRigidBody_getFrictionSolverType(_native); }
			set { btRigidBody_setFrictionSolverType(_native, value); }
		}

		public Vector3 Gravity
		{
			get
			{
				Vector3 value;
				btRigidBody_getGravity(_native, out value);
				return value;
			}
			set { btRigidBody_setGravity(_native, ref value); }
		}

		public Vector3 InvInertiaDiagLocal
		{
			get
			{
				Vector3 value;
				btRigidBody_getInvInertiaDiagLocal(_native, out value);
				return value;
			}
			set { btRigidBody_setInvInertiaDiagLocal(_native, ref value); }
		}

		public Matrix InvInertiaTensorWorld
		{
            get
            {
                Matrix inertiaTensor;
                btRigidBody_getInvInertiaTensorWorld(_native, out inertiaTensor);
                return inertiaTensor;
            }
		}

		public float InvMass
		{
			get { return btRigidBody_getInvMass(_native); }
		}

		public bool IsInWorld
		{
			get { return btRigidBody_isInWorld(_native); }
		}

		public float LinearDamping
		{
			get { return btRigidBody_getLinearDamping(_native); }
		}

		public Vector3 LinearFactor
		{
			get
			{
				Vector3 value;
				btRigidBody_getLinearFactor(_native, out value);
				return value;
			}
			set { btRigidBody_setLinearFactor(_native, ref value); }
		}

		public float LinearSleepingThreshold
		{
			get { return btRigidBody_getLinearSleepingThreshold(_native); }
		}

		public Vector3 LinearVelocity
		{
			get
			{
				Vector3 value;
				btRigidBody_getLinearVelocity(_native, out value);
				return value;
			}
			set { btRigidBody_setLinearVelocity(_native, ref value); }
		}

        /*
        public MotionState MotionState
        {
            get { return _motionState; }
            set
            {
                btRigidBody_setMotionState(_native, value._native);
                _motionState = value;
            }
        }
        */

		public int NumConstraintRefs
		{
			get { return btRigidBody_getNumConstraintRefs(_native); }
		}

		public Quaternion Orientation
		{
            get
            {
                Quaternion value;
                btRigidBody_getOrientation(_native, out value);
                return value;
            }
		}

		public Vector3 TotalForce
		{
			get
			{
				Vector3 value;
				btRigidBody_getTotalForce(_native, out value);
				return value;
			}
		}

		public Vector3 TotalTorque
		{
			get
			{
				Vector3 value;
				btRigidBody_getTotalTorque(_native, out value);
				return value;
			}
		}

		//[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		//static extern IntPtr btRigidBody_new(IntPtr constructionInfo);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btRigidBody_new2(float mass, IntPtr motionState, IntPtr collisionShape, [In] ref Vector3 localInertia);
		//[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		//static extern IntPtr btRigidBody_new3(float mass, IntPtr motionState, IntPtr collisionShape);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_addConstraintRef(IntPtr obj, IntPtr c);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyCentralForce(IntPtr obj, [In] ref Vector3 force);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyCentralImpulse(IntPtr obj, [In] ref Vector3 impulse);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyDamping(IntPtr obj, float timeStep);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyForce(IntPtr obj, [In] ref Vector3 force, [In] ref Vector3 rel_pos);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyGravity(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyImpulse(IntPtr obj, [In] ref Vector3 impulse, [In] ref Vector3 rel_pos);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyTorque(IntPtr obj, [In] ref Vector3 torque);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_applyTorqueImpulse(IntPtr obj, [In] ref Vector3 torque);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern bool btRigidBody_checkCollideWithOverride(IntPtr obj, IntPtr co);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_clearForces(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_computeAngularImpulseDenominator(IntPtr obj, [In] ref Vector3 axis);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_computeGyroscopicForce(IntPtr obj, float maxGyroscopicForce);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_computeImpulseDenominator(IntPtr obj, [In] ref Vector3 pos, [In] ref Vector3 normal);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getAabb(IntPtr obj, [Out] out Vector3 aabbMin, [Out] out Vector3 aabbMax);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_getAngularDamping(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getAngularFactor(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_getAngularSleepingThreshold(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getAngularVelocity(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btRigidBody_getBroadphaseProxy(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getCenterOfMassPosition(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getCenterOfMassTransform(IntPtr obj, [Out] out Matrix value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btRigidBody_getConstraintRef(IntPtr obj, int index);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern int btRigidBody_getContactSolverType(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern RigidBodyFlags btRigidBody_getFlags(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern int btRigidBody_getFrictionSolverType(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getGravity(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getInvInertiaDiagLocal(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getInvInertiaTensorWorld(IntPtr obj, [Out] out Matrix value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_getInvMass(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_getLinearDamping(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getLinearFactor(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btRigidBody_getLinearSleepingThreshold(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getLinearVelocity(IntPtr obj, [Out] out Vector3 value);

	    [DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern int btRigidBody_getNumConstraintRefs(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getOrientation(IntPtr obj, [Out] out Quaternion value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getTotalForce(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_getTotalTorque(IntPtr obj, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_getVelocityInLocalPoint(IntPtr obj, [In] ref Vector3 rel_pos, [Out] out Vector3 value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_integrateVelocities(IntPtr obj, float step);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern bool btRigidBody_isInWorld(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_predictIntegratedTransform(IntPtr obj, float step, [Out] out Matrix predictedTransform);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_proceedToTransform(IntPtr obj, [In] ref Matrix newTrans);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_removeConstraintRef(IntPtr obj, IntPtr c);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_saveKinematicState(IntPtr obj, float step);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setAngularFactor(IntPtr obj, [In] ref Vector3 angFac);

	    [DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setAngularVelocity(IntPtr obj, [In] ref Vector3 ang_vel);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setCenterOfMassTransform(IntPtr obj, [In] ref Matrix xform);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setContactSolverType(IntPtr obj, int value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setDamping(IntPtr obj, float lin_damping, float ang_damping);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern void btRigidBody_setFlags(IntPtr obj, RigidBodyFlags flags);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setFrictionSolverType(IntPtr obj, int value);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setGravity(IntPtr obj, [In] ref Vector3 acceleration);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setInvInertiaDiagLocal(IntPtr obj, [In] ref Vector3 diagInvInertia);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setLinearFactor(IntPtr obj, [In] ref Vector3 linearFactor);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setLinearVelocity(IntPtr obj, [In] ref Vector3 lin_vel);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setMassProps(IntPtr obj, float mass, [In] ref Vector3 inertia);
		//[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		//static extern void btRigidBody_setMotionState(IntPtr obj, IntPtr motionState);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setNewBroadphaseProxy(IntPtr obj, IntPtr broadphaseProxy);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_setSleepingThresholds(IntPtr obj, float linear, float angular);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_translate(IntPtr obj, [In] ref Vector3 v);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btRigidBody_upcast(IntPtr colObj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_updateDeactivation(IntPtr obj, float timeStep);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btRigidBody_updateInertiaTensor(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern bool btRigidBody_wantsSleeping(IntPtr obj);
	}
}
