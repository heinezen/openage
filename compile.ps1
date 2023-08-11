$TOOLCHAIN_FILE = Join-Path download openage-dep-x64-windows scripts buildsystems vcpkg.cmake | Resolve-Path
mkdir build
cd build
cmake -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS='/Zc:__cplusplus /permissive- /EHsc' -DCMAKE_EXE_LINKER_FLAGS='' -DCMAKE_MODULE_LINKER_FLAGS='' -DCMAKE_SHARED_LINKER_FLAGS='' -DDOWNLOAD_NYAN=YES -DCXX_OPTIMIZATION_LEVEL=auto -DCXX_SANITIZE_FATAL=False -DCXX_SANITIZE_MODE=none -DWANT_BACKTRACE=if_available -DWANT_GPERFTOOLS_PROFILER=if_available -DWANT_GPERFTOOLS_TCMALLOC=False -DWANT_INOTIFY=if_available -DWANT_NCURSES=if_available -DWANT_OPENGL=if_available -DWANT_VULKAN=if_available -G "Visual Studio 16 2019" -A x64 ..
cmake --build . --config RelWithDebInfo -- -nologo -maxCpuCount
cd ..
mkdir package
cd package
mkdir dll
cd ..
$STAGING_PATH = Resolve-Path package
$DLL_PATH = Join-Path package dll | Resolve-Path
cd build
$NYAN_DLL = (Get-ChildItem . -Recurse -Force -Filter 'nyan.dll')[0].FullName
$OPENAGE_DLL = (Get-ChildItem . -Recurse -Force -Filter 'openage.dll')[0].FullName
$NATIVE_OUTPUT = Split-Path -Path $OPENAGE_DLL -Parent
Copy-Item -Path ./openage -Destination $STAGING_PATH -Recurse
Copy-Item -Path $NYAN_DLL -Destination $DLL_PATH
Copy-Item -Path (Join-Path $NATIVE_OUTPUT *.dll) -Destination $DLL_PATH
Copy-Item -Path run.* -Destination $STAGING_PATH
cd ..