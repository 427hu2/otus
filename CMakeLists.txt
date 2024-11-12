cmake_minimum_required(VERSION 3.15)

project(lesson_2)

add_executable(lesson_2 main.cpp
        utils.h)

set_target_properties(
        lesson_2
        PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS lesson_2 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT 79771473767@ya.ru)
include(CPack)