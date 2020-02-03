cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/Customer.cpp
        include/CustomerType.h src/Student.cpp include/Student.h src/Pensioner.cpp include/Pensioner.h src/Regular.cpp include/Regular.h src/Normal.cpp include/Normal.h src/Train.cpp include/Train.h src/Booking.cpp include/Booking.h include/Ticket.h src/FirstClass.cpp include/FirstClass.h src/SecondClass.cpp include/SecondClass.h src/ThirdClass.cpp include/ThirdClass.h)

#create shared library of type STATIC, SHARED or MODULE using following source files
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

#Enabling unit tests will add additional target test in Makefile files.
enable_testing()

include_directories(
 ${CMAKE_CURRENT_SOURCE_DIR}/include
 ${Boost_INCLUDE_DIRS}
)

if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

set(SOURCE_TEST_FILES
        test/Master.cpp
        test/CustomerTest.cpp test/TrainTest.cpp test/BookingTest.cpp)

add_executable (TestLibr ${SOURCE_TEST_FILES})

#add library with tested claseses to then test program
target_link_libraries (TestLibr
 Library
 ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

#add test TestWeight to TestContainer. There may be multiple CMake add_test instructions. 
#Additional parameters influence amount of details of generated report. Standard place for report is in Testing/Temporary.
add_test(TestLibrary TestLibr
 --report_level=detailed
 --log_level=all
 --color_output=yes
 )