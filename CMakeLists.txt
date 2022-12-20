cmake_minimum_required(VERSION 3.16)
project(my_test)
set(CMAKE_CXX_STANDARD 17)

add_compile_options(
        #-stdlib=libc++
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)
#add_link_options(
#        -stdlib=libc++
#        -fuse-ld=lld
#)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
#gtest_discover_tests(tests)

#add_executable(my_test main.cpp)

#target_link_libraries(
#        test
#        GTest::gtest_main
#)