cmake_minimum_required(VERSION 3.24...3.30)
project(oef1)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Use local raylib
set(RAYLIB_DIR "c:/raylib/raylib/src")
include_directories(${RAYLIB_DIR})

# Try to find the library in likely locations
find_library(RAYLIB_LIB
        NAMES raylib
        HINTS
        "${RAYLIB_DIR}"
)

# Project
add_executable(${PROJECT_NAME}
        main.cpp
        Monster.h
        Monster.cpp
        Game.cpp
        Game.h
        Pawn.h
        Pawn.cpp
        Player.h
        Player.cpp
        MonsterManager.cpp
        MonsterManager.h
        Singleton.h
        Warning.h
        Warning.cpp
        Gate.cpp
        Gate.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/src
        COMMENT "Copying src assets to build output")

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY $<TARGET_FILE_DIR:${PROJECT_NAME}>)

# Link raylib and system dependencies
if (RAYLIB_LIB)
    target_link_libraries(${PROJECT_NAME} ${RAYLIB_LIB})
else ()
    # Fallback if find_library fails
    link_directories(${RAYLIB_DIR})
    target_link_libraries(${PROJECT_NAME} raylib)
endif ()

# WIN32 allows for both 32-bit and 64-bit Windows systems
if (WIN32)
    # These are required Windows system libraries for raylib (Audio, OpenGL context, etc.)
    target_link_libraries(${PROJECT_NAME} winmm gdi32)
endif ()
