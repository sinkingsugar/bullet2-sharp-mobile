REM Windows
call "%PROGRAMFILES(X86)%\Microsoft Visual Studio 12.0\vc\vcvarsall.bat" x86

pushd ..\..\externals\bullet2-sharp-mobile\src\VHACD_Lib\VHACD
msbuild VHACD.sln /p:Configuration=Release;Platform=x86
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

pushd ..\..\externals\bullet2-sharp-mobile\src\VHACD_Lib\VHACD
msbuild VHACD.sln /p:Configuration=Release;Platform=x64
if %ERRORLEVEL% neq 0 GOTO :error_popd
popd

GOTO :end
:error_popd
popd
echo Error during compilation
EXIT /B %ERRORLEVEL%
pause
:end
