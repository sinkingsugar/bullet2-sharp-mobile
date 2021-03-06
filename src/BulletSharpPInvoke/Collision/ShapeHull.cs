using SiliconStudio.Core.Mathematics;
using System;
using System.Runtime.InteropServices;
using System.Security;

namespace BulletSharp
{
	public class ShapeHull
	{
		internal IntPtr _native;

        UIntArray _indices;
        Vector3Array _vertices;

		internal ShapeHull(IntPtr native)
		{
			_native = native;
		}

		public ShapeHull(ConvexShape shape)
		{
			_native = btShapeHull_new(shape._native);
		}

		public bool BuildHull(float margin)
		{
			return btShapeHull_buildHull(_native, margin);
		}

		public int NumIndices
		{
            get { return btShapeHull_numIndices(_native); }
		}

		public int NumTriangles
		{
            get { return btShapeHull_numTriangles(_native); }
		}

		public int NumVertices
		{
            get { return btShapeHull_numVertices(_native); }
		}

		public UIntArray Indices
		{
            get
            {
                if (_indices == null)
                {
                    _indices = new UIntArray(btShapeHull_getIndexPointer(_native), NumIndices);
                }
                return _indices;
            }
		}

		public Vector3Array Vertices
		{
            get
            {
                if (_vertices == null)
                {
                    _vertices = new Vector3Array(btShapeHull_getVertexPointer(_native), NumVertices);
                }
                return _vertices;
            }
		}

		public void Dispose()
		{
			Dispose(true);
			GC.SuppressFinalize(this);
		}

		protected virtual void Dispose(bool disposing)
		{
			if (_native != IntPtr.Zero)
			{
				btShapeHull_delete(_native);
				_native = IntPtr.Zero;
			}
		}

		~ShapeHull()
		{
			Dispose(false);
		}

		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btShapeHull_new(IntPtr shape);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern bool btShapeHull_buildHull(IntPtr obj, float margin);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btShapeHull_getIndexPointer(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern IntPtr btShapeHull_getVertexPointer(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern int btShapeHull_numIndices(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern int btShapeHull_numTriangles(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern int btShapeHull_numVertices(IntPtr obj);
		[DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
		static extern void btShapeHull_delete(IntPtr obj);
	}
}
