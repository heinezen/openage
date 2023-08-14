# Troubleshooting
 If you have error with it like `CMake Error at scripts/cmake/vcpkg_acquire_msys.cmake:229 (file): file failed to extract:` or a disc in exFAT you can download with this command in powershell
  ```powershell
  mkdir download
  cd download
  $zipfile = "openage-dep-x64-windows.zip"
  Invoke-WebRequest https://github.com/SFTtech/openage-dependencies/releases/download/v0.5.0/openage-dep-x64-windows.zip -OutFile $zipfile
  Expand-Archive -Path $zipfile -DestinationPath . -Force
  Remove-Item $zipfile
  (Get-ChildItem . -Recurse -File).FullName
  ```
  and then add `-DCMAKE_TOOLCHAIN_FILE=<pathToDownloadDir>/openage-dep-x64-windows/scripts/buildsystems/vcpkg.cmake` to the cmake configure command.