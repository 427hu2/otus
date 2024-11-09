cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1 CACHE INTERNAL "Project version")
set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})

project(lesson VERSION ${PROJECT_VERSION})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(config.h.in config.h)

add_executable(lesson_cli main.cpp)
add_library(lesson lib.cpp)
add_executable(test_version test_version.cpp)

set_target_properties(
        lesson_cli
        lesson test_version
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(lesson
        PRIVATE "${CMAKE_BINARY_DIR}"
)

set_target_properties(
        test_version
        PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
)

set_target_properties(
        test_version
        PROPERTIES
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(lesson_cli PRIVATE
        lesson
)

target_link_libraries(test_version
        ${Boost_LIBRARIES}
        lesson
)

install(TARGETS lesson_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT 79771473767@ya.ru)
include(CPack)
enable_testing()
add_test(test_version test_version)
