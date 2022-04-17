cmake_minimum_required(VERSION 3.9)
project(C_ed)

set(CMAKE_CXX_STANDARD 17)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})


add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(
        C_ed_run
        с/les1.cpp
        с/les2.cpp
        с/les3.cpp
        с/valLes3.cpp
        с/les4.cpp
        ch/chall3.cpp
        c_ed_headers.h
        ch/bitmap_image.hpp
        с/les6.cpp
        oop/source.cpp
        с/les7.cpp
        oop/source.h
        oop/oop1.cpp
        с/les5.cpp
        с/sources.cpp
        с/sourses.h
        oop/oop2.cpp
        oop/oop3.cpp
        oop/oop4.cpp
        c-hard/hardsource.cpp
        c-hard/hardsource.h
        c-hard/hard1.cpp
        oop/oop5.cpp c-hard/hard2.cpp

        c-hard/hard3.cpp
        c-hard/hatd4.cpp
        c-hard/hard5.cpp
        c-hard/hard6.cpp
        c-hard/hard7.cpp
        ${PROTO_SRCS} ${PROTO_HDRS}

        c-hard/hard8.cpp c-hard/hard1.h)

target_link_libraries(C_ed_run gtest gtest_main)