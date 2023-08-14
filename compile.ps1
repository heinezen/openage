# path to dependencies
$TOOLCHAIN_FILE = Join-Path download openage-dep-x64-windows scripts buildsystems vcpkg.cmake | Resolve-Path

# create a dir
mkdir build
cd build

# compile
cmake -DCMAKE_TOOLCHAIN_FILE="$TOOLCHAIN_FILE" -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config RelWithDebInfo -- -nologo -maxCpuCount

# creating package folder
mkdir package
cd package
mkdir dll
cd ..
$STAGING_PATH = Resolve-Path package
$DLL_PATH = Join-Path package dll | Resolve-Path

# copy all dll needed
$NYAN_DLL = (Get-ChildItem . -Recurse -Force -Filter 'nyan.dll')[0].FullName # he don't find so he need to be fixed
$OPENAGE_DLL = (Get-ChildItem . -Recurse -Force -Filter 'openage.dll')[0].FullName
$NATIVE_OUTPUT = Split-Path -Path $OPENAGE_DLL -Parent
Copy-Item -Path ./openage -Destination $STAGING_PATH -Recurse
Copy-Item -Path $NYAN_DLL -Destination $DLL_PATH
Copy-Item -Path (Join-Path $NATIVE_OUTPUT *.dll) -Destination $DLL_PATH
Copy-Item -Path run.* -Destination $STAGING_PATH
cd ..