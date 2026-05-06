cmake_minimum_required(VERSION 3.15)

project(RationalClass)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# добавление заголовочного файла проекта 
add_library(rational_lib INTERFACE)
target_include_directories(rational_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# добавление GOOGLE TEST
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# добавление тестового выполняемого файла
add_executable(rational_tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_rational.cpp)

target_link_libraries(rational_tests
    PRIVATE
        rational_lib
        gtest_main
        gtest
)

enable_testing()
include(GoogleTest)
gtest_discover_tests(rational_tests)
