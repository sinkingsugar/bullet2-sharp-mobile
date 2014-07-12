using SiliconStudio.Core.Mathematics;
﻿using System;
using System.Runtime.InteropServices;
using System.Security;


namespace BulletSharp
{
    public class Box2DShape : PolyhedralConvexShape
    {
        internal Box2DShape(IntPtr native)
			: base(native)
		{
		}

        public Box2DShape(float boxHalfExtent)
            : base(btBox2dShape_new(boxHalfExtent))
        {
        }

        [DllImport(Native.Dll, CallingConvention = Native.Conv), SuppressUnmanagedCodeSecurity]
        static extern IntPtr btBox2dShape_new(float halfExtent);
    }
}
