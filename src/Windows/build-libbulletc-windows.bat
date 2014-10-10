REM Windows
call "%PROGRAMFILES(X86)%\Microsoft Visual Studio 12.0\vc\vcvarsall.bat" x86

mkdir ..\build\bulletc\Windows\x86
pushd ..\build\bulletc\Windows\x86
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013" -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\Windows\x86\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bulletc\Windows\x64
pushd ..\build\bulletc\Windows\x64
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013 Win64" -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\Windows\x64\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Store
mkdir ..\build\bulletc\WindowsStore\x86
pushd ..\build\bulletc\WindowsStore\x86
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\WindowsStore\x86\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bulletc\WindowsStore\x64
pushd ..\build\bulletc\WindowsStore\x64
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013 Win64" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\WindowsStore\x64\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bulletc\WindowsStore\ARM
pushd ..\build\bulletc\WindowsStore\ARM
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013 ARM" -DCMAKE_SYSTEM_NAME=WindowsStore -DCMAKE_SYSTEM_VERSION=8.1 -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\WindowsStore\ARM\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

REM Windows Phone
mkdir ..\build\bulletc\WindowsPhone\x86
pushd ..\build\bulletc\WindowsPhone\x86
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013" -DCMAKE_SYSTEM_NAME=WindowsPhone -DCMAKE_SYSTEM_VERSION=8.1 -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\WindowsPhone\x86\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

mkdir ..\build\bulletc\WindowsPhone\ARM
pushd ..\build\bulletc\WindowsPhone\ARM
cmake ..\..\..\..\libbulletc\ -G "Visual Studio 12 2013 ARM" -DCMAKE_SYSTEM_NAME=WindowsPhone -DCMAKE_SYSTEM_VERSION=8.1 -DBUILD_MULTITHREADING=OFF -DBULLET_LIBS_DIR=..\..\..\bullet\WindowsPhone\ARM\lib
msbuild libbulletc.sln /p:Configuration=Release
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

GOTO :end
:error_popd
popd
echo Error during compilation
EXIT /B %ERRORLEVEL%
pause
:end
