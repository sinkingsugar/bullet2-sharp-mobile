// Copyright (c) 2014 Silicon Studio Corp. (http://siliconstudio.co.jp)
// This file is distributed under GPL v3. See LICENSE.md for details.
#if !__iOS__
using System;
using System.Runtime.InteropServices;
namespace System.Security
{
    [AttributeUsageAttribute(
        AttributeTargets.Class | AttributeTargets.Method | AttributeTargets.Interface | AttributeTargets.Delegate,
        AllowMultiple = true,
        Inherited = false)]
    [ComVisible(true)]
    public sealed class SuppressUnmanagedCodeSecurityAttribute : Attribute
    {
    }
}
#endif