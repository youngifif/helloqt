# A Simple Qt6 Project Structure 

Using `CMake` as well as `Visual Studio 2022 Community Edition` ,and `vcpkg`


## Version
- `Qt6` 6.8.1
- `CMake` 3.31



## Usage - Prerequisites
Install `vcpkg.exe`,

then
```cmd
set VCPKG_ROOT=C:/_path_/_to_/vcpkg_root_dir
```

Install `qtbase` from `vcpkg.io`

```cmd
vcpkg.exe install qtbase:x64-windows
```
or install static library

```cmd
vcpkg.exe install qtbase:x64-windows-static
```

## Build - Visual Studio Code


- Open the directory in `vscode` after install `CMake Tools Extension`

- Using `Ctrl + Shift + P` to open pannel,then choose `CMake: Select Build Preset`


## Build - CLI




For Release-dynamic
```
cmake -S .  --preset "vs2022" -DUSE_STATIC_LIBS=OFF
cmake --build --preset  "vs2022-rel"
%VCPKG_ROOT%/installed/x64-windows/tools/Qt6/bin/windeployqt.exe out/build/vs2022/Release/helloqt.exe"
```

For Debug-dynamic (use windeployqt.debug.bat,not windeployqt.exe)
```
cmake -S . --preset "vs2022"  -DUSE_STATIC_LIBS=OFF
cmake --build --preset  "vs2022-dbg"
%VCPKG_ROOT%\\installed\\x64-windows\\tools\\Qt6\\bin\\windeployqt.debug.bat helloqt.exe
```


For Debug-static (qtbase:x64-windows-static)
```
cmake -S . --preset "vs2022" -DUSE_STATIC_LIBS=ON
cmake --build --preset  "vs2022-dbg"
```

For Release-static (qtbase:x64-windows-static)
```
cmake -S .  --preset "vs2022" -DUSE_STATIC_LIBS=ON
cmake --build --preset  "vs2022-rel" -DUSE_STATIC_LIBS=ON
```



