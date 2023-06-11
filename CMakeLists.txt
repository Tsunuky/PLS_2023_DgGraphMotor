cmake_minimum_required(VERSION 3.12)
project(moteur3D CXX)

set(CMAKE_CXX_STANDARD 20)

# Include directories for header files
include_directories(
    include
    include/event
    include/imGui
    submodule/spdlog/include
    submodule/imgui
    submodule/glm
)

# Automatic submodule downloading
execute_process(
    COMMAND git submodule update --init --recursive --remote
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    RESULT_VARIABLE GIT_SUBMODULE_RESULT
)

# Automatic search and configuration of OpenGL library
find_package(OpenGL REQUIRED)

# List of required libraries for the project
set(REQUIRED_LIBRARIES
    ${OPENGL_LIBRARIES}
    fmt
    GLEW
    stdc++
    m
    dl
    gcc_s
    avcall
    GL
    GLU
    glut
)

# Path to imGui library files
set(IMGUI_DIR submodule/imgui)

# Add imGui library directory to the include directories list
include_directories(${IMGUI_DIR})

# Add the imGui library source file to the source files list
list(APPEND SOURCES ${IMGUI_DIR}/imgui.cpp)

# Add the imGui library to the list of required libraries
list(APPEND REQUIRED_LIBRARIES imGui)

# Function to find the package manager
function(find_package_manager PACKAGE_MANAGER)
    # Check if apt package manager is available
    find_program(APT_PROGRAM apt)
    if(APT_PROGRAM)
        set(${PACKAGE_MANAGER} ${APT_PROGRAM} PARENT_SCOPE)
        return()
    endif()

    # Check if dnf package manager is available
    find_program(DNF_PROGRAM dnf)
    if(DNF_PROGRAM)
        set(${PACKAGE_MANAGER} ${DNF_PROGRAM} PARENT_SCOPE)
        return()
    endif()

    # Check if pacman package manager is available
    find_program(PACMAN_PROGRAM pacman)
    if(PACMAN_PROGRAM)
        set(${PACKAGE_MANAGER} ${PACMAN_PROGRAM} PARENT_SCOPE)
        return()
    endif()

    # Add other package managers here if necessary
    message(FATAL_ERROR "No compatible package manager found.")
endfunction()

# Function to find and install a library if it is missing
function(install_library TARGET_NAME LIBRARY_NAME PACKAGE_NAME)
    # Check if the library is already found
    find_package(${LIBRARY_NAME} QUIET)

    # Automatic installation if the library is missing
    if(NOT ${LIBRARY_NAME}_FOUND)
        message(STATUS "Library ${PACKAGE_NAME} is missing. Attempting automatic installation.")
        message(STATUS "Using package manager: ${PACKAGE_MANAGER}")

        # Install the package using the package manager with sudo
        execute_process(
            COMMAND sudo ${PACKAGE_MANAGER} install -y ${PACKAGE_NAME}
            RESULT_VARIABLE INSTALL_RESULT
            OUTPUT_VARIABLE INSTALL_OUTPUT
        )

        if(INSTALL_RESULT EQUAL 0)
            message(STATUS "Successfully installed ${PACKAGE_NAME}.")
        else()
            message(FATAL_ERROR "Failed to install ${PACKAGE_NAME}. Please install ${PACKAGE_NAME} manually.")
        endif()
    endif()

    # Add the library to the list of required libraries
    list(APPEND REQUIRED_LIBRARIES ${${LIBRARY_NAME}_LIBRARY})
endfunction()

find_package_manager(PACKAGE_MANAGER)

# Install missing libraries based on the package manager
if (PACKAGE_MANAGER MATCHES "apt")
    install_library(OpenGL "OpenGL" "libgl1-mesa-dev")
    install_library(GLUT "GLUT" "freeglut3-dev")
    install_library(fmt "fmt" "libfmt-dev")
    install_library(glfw3 "glfw3" "libglfw3-dev")
    install_library(GLEW "GLEW" "libglew-dev")
    install_library(glm "glm" "libglm-dev")
    install_library(avcall "avcall" "libffcall-dev")
elseif (PACKAGE_MANAGER MATCHES "dnf")
    install_library(OpenGL "OpenGL" "mesa-libGL-devel")
    install_library(GLUT "GLUT" "freeglut-devel")
    install_library(fmt "fmt" "fmt-devel")
    install_library(glfw3 "glfw3" "glfw-devel")
    install_library(GLEW "GLEW" "glew-devel")
    install_library(glm "glm" "glm-devel")
    install_library(avcall "avcall" "ffcall-devel")
elseif (PACKAGE_MANAGER MATCHES "pacman")
    install_library(OpenGL "OpenGL" "mesa")
    install_library(GLUT "GLUT" "freeglut")
    install_library(fmt "fmt" "fmt")
    install_library(glfw3 "glfw3" "glfw-x11")
    install_library(GLEW "GLEW" "glew")
    install_library(glm "glm" "glm")
    install_library(avcall "avcall" "ffcall")
endif()

# Add other libraries to install here if necessary

# Source files
file(GLOB SOURCES src/*.cpp src/imGui/*.cpp)

# Target for precompiled headers
set(PCH_SRC include/precompile/precompile.hpp)
add_library(precompiled_header OBJECT ${PCH_SRC})
set_source_files_properties(${PCH_SRC} PROPERTIES COMPILE_FLAGS "-std=c++20 -O2")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES} $<TARGET_OBJECTS:precompiled_header>)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBRARIES})

# Project dependency on precompiled headers
add_dependencies(${PROJECT_NAME} precompiled_header)

# Compiler options
target_compile_options(${PROJECT_NAME} PRIVATE -W -Wall -Wextra -g3)

# Set compiled file
foreach(SRC ${SOURCES})
    # replace .cpp extension with .o
    string(REGEX REPLACE ".cpp$" ".o" OBJ ${SRC})
    list(APPEND COMPILED_FILE ${OBJ})
endforeach()


# Rules for clean and fclean targets
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E remove -f ${COMPILED_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(fclean_all DEPENDS clean_all
    COMMAND ${CMAKE_COMMAND} -E remove -f ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E remove -f include/precompile.hpp.gch
    # COMMAND ${CMAKE_COMMAND} -E remove_directory ${SPDLOG_DIR}
    # COMMAND ${CMAKE_COMMAND} -E remove_directory ${IMGUI_DIR}
    # COMMAND ${CMAKE_COMMAND} -E remove_directory ${GLM_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

# Aliases for all and re targets
add_custom_target(all_target
    DEPENDS ${PROJECT_NAME}
)

add_custom_target(re_target
    DEPENDS fclean_all all_target
)

# Rules for clean and fclean targets
add_custom_target(r_clean DEPENDS clean_all)
add_custom_target(fclean DEPENDS fclean_all)

# Aliases for all and re targets
add_custom_target(c_all DEPENDS all_target)
add_custom_target(re DEPENDS re_target)
