cmake_minimum_required(VERSION 3.31)

#set %VCPKG_ROOT%
option(USE_STATIC_LIBS "Library linking option" OFF)


if(USE_STATIC_LIBS) 

    # vcpkg install qtbase:x64-windows-static
    set(VCPKG_TARGET_TRIPLET "x64-windows-static")
    set(VCPKG_CRT_LINKAGE static)
    set(VCPKG_LIBRARY_LINKAGE static)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    message(STATUS "!!! Using  static library to build")
else()
    set(VCPKG_TARGET_TRIPLET "x64-windows")
    set(VCPKG_CRT_LINKAGE dynamic )
    set(VCPKG_LIBRARY_LINKAGE dynamic )
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
    
    message(STATUS "!!! Using  dynamic library to build")
    message(STATUS "!!! After Build,remember to run cmd: %VCPKG_ROOT%\\installed\\x64-windows\\tools\\Qt6\\bin\\windeployqt.exe helloqt.exe")
endif()


project(helloqt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Gui)
qt_standard_project_setup()

add_subdirectory(src/app)