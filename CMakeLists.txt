cmake_minimum_required(VERSION 3.16...3.18)

project(
  sfml-template
  VERSION 0.1.0
  DESCRIPTION "An SFML Project"
  LANGUAGES CXX)

# List warnings and errors to be used by internal targets.
#
# NOTE: Some of these are quite new and might require newer versions of
# compilers then those usually distributed.
set(COMPILER_WARNINGS_AND_ERRORS
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:MSVC>:/w44061>
    $<$<CXX_COMPILER_ID:MSVC>:/w44062>
    $<$<CXX_COMPILER_ID:MSVC>:/w44265>
    $<$<CXX_COMPILER_ID:MSVC>:/w44267>
    $<$<CXX_COMPILER_ID:MSVC>:/permissive->
    $<$<CXX_COMPILER_ID:GNU>:-Wmisleading-indentation>
    $<$<CXX_COMPILER_ID:GNU>:-Wduplicated-cond>
    $<$<CXX_COMPILER_ID:GNU>:-Wduplicated-branches>
    $<$<CXX_COMPILER_ID:GNU>:-Wlogical-op>
    $<$<CXX_COMPILER_ID:GNU>:-Wnull-dereference>
    $<$<CXX_COMPILER_ID:GNU>:-Wuseless-cast>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wdocumentation>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wweak-vtables>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wexit-time-destructors>
    $<$<CXX_COMPILER_ID:Clang,AppleClang>:-Wglobal-constructors>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wall>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wextra>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wpedantic>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wshadow>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wnon-virtual-dtor>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Woverloaded-virtual>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wunreachable-code>
    $<$<CXX_COMPILER_ID:Clang,AppleClang,GNU>:-Wmissing-noreturn>)

# Dependencies
# ******************************************************************

include(FetchContent)

# Fetch sfml from github
FetchContent_Declare(
	sfml
	GIT_REPOSITORY https://github.com/SFML/SFML
	GIT_TAG 2.5.1
)
set(BUILD_SHARED_LIBS FALSE)
FetchContent_MakeAvailable(sfml)

# If you have a different way to install SFML, you can use this to find it.
# find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics)

# Setup individual exercises as buildable targets
# ******************************************************************

# Set C++ standard
set(CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS OFF)

# Define a simple window example
add_executable(window src/window.cpp)
target_link_libraries(window PRIVATE sfml-system sfml-window sfml-graphics)
target_compile_options(window PRIVATE ${COMPILER_WARNINGS_AND_ERRORS})
