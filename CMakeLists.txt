cmake_minimum_required(VERSION 3.12)
project(refactoring CXX)

add_compile_options(-Wall -Wextra -pedantic -Werror)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

add_executable(main
        source/main.cpp)

add_executable(tests
        tests/tests.cpp)

target_include_directories(main PUBLIC include)
target_include_directories(tests PUBLIC include)
target_link_libraries(tests gmock_main gtest gmock)
target_compile_features(main PUBLIC cxx_std_20)
target_compile_features(tests PUBLIC cxx_std_20)

enable_testing()
add_test(tests tests)
