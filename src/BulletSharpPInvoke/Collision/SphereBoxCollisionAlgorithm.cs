using SiliconStudio.Core.Mathematics;
using System;
using System.Runtime.InteropServices;
using System.Security;

namespace BulletSharp
{
	public class SphereBoxCollisionAlgorithm : ActivatingCollisionAlgorithm
	{
		public class CreateFunc : CollisionAlgorithmCreateFunc
		{
			internal CreateFunc(IntPtr native)
				: base(native)
			{
			}

			public CreateFunc()
				: base(btSphereBoxCollisionAlgorithm_CreateFunc_new())
			{
			}

			[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
			static extern IntPtr btSphereBoxCollisionAlgorithm_CreateFunc_new();
		}

		internal SphereBoxCollisionAlgorithm(IntPtr native)
			: base(native)
		{
		}

		public SphereBoxCollisionAlgorithm(PersistentManifold mf, CollisionAlgorithmConstructionInfo ci, CollisionObjectWrapper body0Wrap, CollisionObjectWrapper body1Wrap, bool isSwapped)
			: base(btSphereBoxCollisionAlgorithm_new(mf._native, ci._native, body0Wrap._native, body1Wrap._native, isSwapped))
		{
		}

		public bool GetSphereDistance(CollisionObjectWrapper boxObjWrap, Vector3 v3PointOnBox, Vector3 normal, out float penetrationDepth, Vector3 v3SphereCenter, float fRadius, float maxContactDistance)
		{
			return btSphereBoxCollisionAlgorithm_getSphereDistance(_native, boxObjWrap._native, ref v3PointOnBox, ref normal, out penetrationDepth, ref v3SphereCenter, fRadius, maxContactDistance);
		}

		public float GetSpherePenetration(Vector3 boxHalfExtent, Vector3 sphereRelPos, Vector3 closestPoint, Vector3 normal)
		{
			return btSphereBoxCollisionAlgorithm_getSpherePenetration(_native, ref boxHalfExtent, ref sphereRelPos, ref closestPoint, ref normal);
		}

		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btSphereBoxCollisionAlgorithm_new(IntPtr mf, IntPtr ci, IntPtr body0Wrap, IntPtr body1Wrap, bool isSwapped);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern bool btSphereBoxCollisionAlgorithm_getSphereDistance(IntPtr obj, IntPtr boxObjWrap, [In] ref Vector3 v3PointOnBox, [In] ref Vector3 normal, [Out] out float penetrationDepth, [In] ref Vector3 v3SphereCenter, float fRadius, float maxContactDistance);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern float btSphereBoxCollisionAlgorithm_getSpherePenetration(IntPtr obj, [In] ref Vector3 boxHalfExtent, [In] ref Vector3 sphereRelPos, [In] ref Vector3 closestPoint, [In] ref Vector3 normal);
	}
}
