cmake_minimum_required(VERSION 3.17)
project(EjerciciosTeleC)

set(CMAKE_C_STANDARD 11)

add_executable(Ej1 Guia1/main1.c)
add_executable(Ej2 Guia1/main2.c)
add_executable(Ej4 Guia1/main4.c)
add_executable(Ej6 Guia1/main6.c)
add_executable(Ej7 Guia1/main7.c)
add_executable(Ej7-2 Guia1/main7-2.c)
add_executable(ejemploGuia21 Guia2/ejemplo1.c)
add_executable(ejemploGuia22 Guia2/ejemplo2.c)
add_executable(ejemploGuia23 Guia2/ejemplo3.c)
add_executable(G2Ej6 Guia2/ej6.c)
add_executable(G2Ej9 Guia2/ej9.c)

add_executable(test test/test1.c)


find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake
if (NOT raylib_FOUND) # if coudnt find it, download and install it
    include(FetchContent)
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/3.0.0.zip
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games
        # build raylib
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
        set(raylib_LDFLAGS "raylib")
        set(raylib_INCLUDE_DIRS "${raylib_BINARY_DIR}/src")
    endif()
endif()

add_executable(mi_raylib ej_raylib/mainRaylib.c)
add_dependencies(mi_raylib raylib)
target_link_libraries(mi_raylib ${raylib_LDFLAGS})
target_include_directories(mi_raylib PRIVATE ${raylib_INCLUDE_DIRS})