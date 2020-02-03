#Minimal version of cmake required to build this project
cmake_minimum_required(VERSION 3.4)

#Configuration parameters for development platform and compiler flags
set(CMAKE_CXX_COMPILER g++)  #g++ as C++ compiler
set(CMAKE_C_COMPILER gcc)    #gcc as C compiler
set(CMAKE_CXX_STANDARD 11)   #Standard C++11, without this g++ will use its defaults. For g++ since version 6 it is C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)  #Defined above version of C++ standard is required

#Set debug profile, also maximum level of debug info g3 and format of debug info to dwarf-4 (requires gdb in version 7)
#BUILD_TYPE can be set to może być ustawiony na:
#empty,
#Debug,
#Release,
#RelWithDebInfo
#MinSizeRel
set(CMAKE_BUILD_TYPE Debug)
if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
endif()
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4 -Werror")
endif()

#Set name of the project and language used to C++
project(RailwayTicketsSystem)
enable_language(CXX)

#In extra file compile_commands.json you can look at all compiler commands with parameters.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 
set(CMAKE_VERBOSE_MAKEFILE TRUE) 

#Include subproject residing in subdirectory program. Inside this subdirectory the file CMakeLists.txt has to be present there.
add_subdirectory(program)

#Include subproject residing in subdirectory library.
add_subdirectory(library)

#Enabling unit tests will add additional target test in Makefile files.
enable_testing()

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})