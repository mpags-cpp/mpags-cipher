# - Main CMake buildscript for mpags-cipher
# Comments in a CMake Script are lines begining with a '#'

# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. This can also be done by removing the 'set' command and
#   running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Don't allow C++ Compiler Vendor Extensions
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags if GNU/Clang compilers are used
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")
endif()

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher
  mpags-cipher.cpp
  MPAGSCipher/ProcessCommandLine.hpp
  MPAGSCipher/ProcessCommandLine.cpp
  MPAGSCipher/TransformChar.hpp
  MPAGSCipher/TransformChar.cpp
  )
target_include_directories(mpags-cipher
  PRIVATE MPAGSCipher
  )
target_compile_features(mpags-cipher
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )

