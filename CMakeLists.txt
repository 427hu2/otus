cmake_minimum_required(VERSION 3.15)

project(lesson_2)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set_target_properties(
        lesson_2
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

add_executable(lesson_2 main.cpp)

target_link_libraries(test_version
        ${Boost_LIBRARIES}
        lesson_2
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