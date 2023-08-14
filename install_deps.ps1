mkdir download
cd download
$zipfile = "openage-dep-x64-windows.zip"
Invoke-WebRequest https://github.com/SFTtech/openage-dependencies/releases/download/v0.5.0/openage-dep-x64-windows.zip -OutFile $zipfile
Expand-Archive -Path $zipfile -DestinationPath . -Force
Remove-Item $zipfile
(Get-ChildItem . -Recurse -File).FullName

$zipfile = "winflexbison-2.5.24.zip"
Invoke-WebRequest https://github.com/lexxmark/winflexbison/releases/download/v2.5.24/win_flex_bison-2.5.24.zip -OutFile $zipfile
mkdir winflexbison
Expand-Archive -Path $zipfile -DestinationPath ./winflexbison -Force
Remove-Item $zipfile
(Get-ChildItem ./winflexbison -Recurse -File).FullName
cd ..

python -m pip install --upgrade pip
python -m pip install --upgrade Cython wheel numpy lz4 toml pillow pygments pyreadline3 mako

git clone https://github.com/SFTtech/nyan.git
$FLEX_PATH = (Get-ChildItem ./download -Recurse -Force -Filter 'win_flex.exe')[0].FullName
cd nyan
mkdir build
cd build
cmake .. -DFLEX_EXECUTABLE="$FLEX_PATH"
cmake --build . --config RelWithDebInfo
cd ../..