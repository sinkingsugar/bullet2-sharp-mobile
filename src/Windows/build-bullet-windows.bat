call "%PROGRAMFILES(X86)%\Microsoft Visual Studio 14.0\vc\vcvarsall.bat" x86
set WindowsSdkDir=

REM Windows
mkdir ..\build\bullet\Windows\x86
pushd ..\build\bullet\Windows\x86
cmake ..\..\..\..\bullet\ -G "Visual Studio 14" -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bullet\Windows\x64
pushd ..\build\bullet\Windows\x64
cmake ..\..\..\..\bullet\ -G "Visual Studio 14 Win64" -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Store
mkdir ..\build\bullet\WindowsStore\x86
pushd ..\build\bullet\WindowsStore\x86
cmake ..\..\..\..\bullet\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bullet\WindowsStore\x64
pushd ..\build\bullet\WindowsStore\x64
cmake ..\..\..\..\bullet\ -G "Visual Studio 14 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bullet\WindowsStore\ARM
pushd ..\build\bullet\WindowsStore\ARM
cmake ..\..\..\..\bullet\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Phone
mkdir ..\build\bullet\WindowsPhone\ARM
pushd ..\build\bullet\WindowsPhone\ARM
cmake ..\..\..\..\bullet\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsPhone -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bullet\WindowsPhone\x86
pushd ..\build\bullet\WindowsPhone\x86
cmake ..\..\..\..\bullet\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsPhone -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

@REM Windows 10
@REM Not properly supported by CMake yet, so use Windows Store and replace a few items of interest in .vcxproj
mkdir ..\build\bullet\Windows10\x86
pushd ..\build\bullet\Windows10\x86
cmake ..\..\..\..\bullet\ -G "Visual Studio 14" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
..\..\..\..\Windows\fart -rC *.vcxproj "<PlatformToolset>v120</PlatformToolset>" "<PlatformToolset>v140</PlatformToolset>"
..\..\..\..\Windows\fart -rC *.vcxproj "<ApplicationTypeRevision>8.1</ApplicationTypeRevision>" "<ApplicationTypeRevision>10.0</ApplicationTypeRevision>\r\n    <WindowsTargetPlatformVersion>10.0.10240.0</WindowsTargetPlatformVersion>\r\n    <WindowsTargetPlatformMinVersion>10.0.10240.0</WindowsTargetPlatformMinVersion>\r\n    <Keyword>DynamicLibrary</Keyword>"
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bullet\Windows10\x64
pushd ..\build\bullet\Windows10\x64
cmake ..\..\..\..\bullet\ -G "Visual Studio 14 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
..\..\..\..\Windows\fart -rC *.vcxproj "<PlatformToolset>v120</PlatformToolset>" "<PlatformToolset>v140</PlatformToolset>"
..\..\..\..\Windows\fart -rC *.vcxproj "<ApplicationTypeRevision>8.1</ApplicationTypeRevision>" "<ApplicationTypeRevision>10.0</ApplicationTypeRevision>\r\n    <WindowsTargetPlatformVersion>10.0.10240.0</WindowsTargetPlatformVersion>\r\n    <WindowsTargetPlatformMinVersion>10.0.10240.0</WindowsTargetPlatformMinVersion>\r\n    <Keyword>DynamicLibrary</Keyword>"
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bullet\Windows10\ARM
pushd ..\build\bullet\Windows10\ARM
cmake ..\..\..\..\bullet\ -G "Visual Studio 14 ARM" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DUSE_MSVC_RUNTIME_LIBRARY_DLL=ON -DBUILD_MULTITHREADING=OFF
..\..\..\..\Windows\fart -rC *.vcxproj "<PlatformToolset>v120</PlatformToolset>" "<PlatformToolset>v140</PlatformToolset>"
..\..\..\..\Windows\fart -rC *.vcxproj "<ApplicationTypeRevision>8.1</ApplicationTypeRevision>" "<ApplicationTypeRevision>10.0</ApplicationTypeRevision>\r\n    <WindowsTargetPlatformVersion>10.0.10240.0</WindowsTargetPlatformVersion>\r\n    <WindowsTargetPlatformMinVersion>10.0.10240.0</WindowsTargetPlatformMinVersion>\r\n    <Keyword>DynamicLibrary</Keyword>"
msbuild BULLET_PHYSICS.sln /p:Configuration=Release /t:LinearMath:Rebuild;BulletCollision:Rebuild;BulletDynamics:Rebuild;BulletFileLoader:Rebuild;BulletSoftBody:Rebuild;BulletWorldImporter:Rebuild;BulletXmlWorldImporter:Rebuild
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

GOTO :end
:error_popd
popd
echo Error during compilation
EXIT /B %ERRORLEVEL%
pause
:end
