cmake_minimum_required(VERSION 3.24)

project(vtable-link
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_library(mylib SHARED
    mylib.cpp
)
target_compile_definitions(mylib
    PRIVATE -DBUILDING_MYLIB=1
    PUBLIC -DMYLIB_SHARED=1
)
if(NOT WIN32)
    target_compile_options(mylib PRIVATE
        -fvisibility=hidden
        -fvisibility-inlines-hidden
    )
endif()

add_executable(main main.cpp)
target_link_libraries(main PRIVATE mylib)
