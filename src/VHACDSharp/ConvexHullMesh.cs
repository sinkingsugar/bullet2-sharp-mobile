using System;
using System.Runtime.InteropServices;
using System.Security;

namespace VHACDSharp
{
    public class ConvexHullMesh : IDisposable
    {
        private readonly IntPtr _internalCompound;

        public struct DecompositionDesc
        {
            public uint VertexCount;
            public uint IndicesCount;
            public float[] Vertexes;
            public uint[] Indices;

            public uint Depth;
            public float Cpercent;
            public float Ppercent;
            public uint MaxVerts;
            public float SkinWidth;
        }

        public ConvexHullMesh(DecompositionDesc desc)
        {
            _internalCompound = GenerateCompoundShape(desc.VertexCount, desc.IndicesCount, desc.Vertexes, desc.Indices,
                desc.Depth, desc.Cpercent, desc.Ppercent, desc.MaxVerts, desc.SkinWidth);
        }

        public uint Count
        {
            get { return GetNumHulls(_internalCompound); }
        }

        public void CopyPoints(uint index, out float[] points)
        {
            points = new float[GetHullNumPoints(_internalCompound, index)];
            CopyHullPoints(_internalCompound, index, points);
        }

        public void CopyIndices(uint index, out uint[] indices)
        {
            indices = new uint[GetHullNumIndices(_internalCompound, index)];
            CopyHullIndices(_internalCompound, index, indices);
        }

        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern IntPtr GenerateCompoundShape(uint vertexCount, uint indicesCount, [In] float[] vertexes, [In] uint[] indices, uint depth, float cpercent, float ppercent, uint maxVerts, float skinWidth);
        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern void DeleteHulls(IntPtr hulls);

        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern uint GetNumHulls(IntPtr hulls);

        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern uint GetHullNumPoints(IntPtr hulls, uint index);
        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern void CopyHullPoints(IntPtr hulls, uint index, [Out] float[] outPoints);

        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern uint GetHullNumIndices(IntPtr hulls, uint index);
        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern void CopyHullIndices(IntPtr hulls, uint index, [Out] uint[] outPoints);

        public void Dispose()
        {
            if (_internalCompound != IntPtr.Zero)
            {
                DeleteHulls(_internalCompound);
            }
        }
    }
}
