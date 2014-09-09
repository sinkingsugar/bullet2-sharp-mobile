using System;
using System.Runtime.InteropServices;
using System.Security;
using BulletSharp;

namespace VHACDSharp
{
    public class VhacdMesh : IDisposable
    {
        private readonly IntPtr _internalMesh;

        public VhacdMesh(uint vertexCount, uint indicesCount, float[] vertexes, int[] indices)
        {
            _internalMesh = CreateMesh(vertexCount, indicesCount, ref vertexes, ref indices);
        }

        public CompoundShape BuildCompoundShape(int depth, int posSampling, int angleSampling, int posRefine, int angleRefine, double alpha, double concavityThreshold)
        {
            var shapePtr = GenerateCompoundShape(_internalMesh, depth, posSampling, angleSampling, posRefine, angleRefine, alpha, concavityThreshold);
            return new CompoundShape(shapePtr);
        }

        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern IntPtr CreateMesh(uint vertexCount, uint indicesCount, [In] ref float[] vertexes, [In] ref int[] indices);
        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern void DeleteMesh(IntPtr mesh);
        [DllImport("VHACD", CallingConvention = CallingConvention.Cdecl), SuppressUnmanagedCodeSecurity]
        private static extern IntPtr GenerateCompoundShape(IntPtr mesh, int depth, int posSampling, int angleSampling, int posRefine, int angleRefine, double alpha, double concavityThreshold);

        public void Dispose()
        {
            if (_internalMesh != IntPtr.Zero)
            {
                DeleteMesh(_internalMesh);
            }
        }
    }
}
