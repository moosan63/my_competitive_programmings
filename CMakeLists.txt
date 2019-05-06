cmake_minimum_required(VERSION 3.7)
project(atcoder)

set(CMAKE_CXX_STANDARD 14)

set(TARGET_CONTEST contests/agc033)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-command-line-argument -I/usr/local/include/c++/v1 -L/usr/local/lib -I/opt/boost/clang/include -L/opt/boost/clang/lib -std=c++14 -stdlib=libc++")

# if(DEFINED FOR_SAMPLE_TEST)
#########   add_definitions(-DFOR_SAMPLE_TEST)
#    message("FOR_SAMPLE_TEST on")
# endif()

get_filename_component(CONTEST_NAME ${TARGET_CONTEST} NAME_WE)
add_definitions(-DCONTEST_NAME="${CONTEST_NAME}")

file(GLOB SOURCES ${TARGET_CONTEST}/*.cpp)
foreach (SOURCE ${SOURCES})
    get_filename_component(PROBLEM ${SOURCE} NAME_WE)
    add_executable(${PROBLEM} ${SOURCE})

    string(TOLOWER ${PROBLEM} LOWER_PROBLEM)
    #    set(SAMPLE ${CONTEST_NAME}_${LOWER_PROBLEM}_0.in)
    #    set(SAMPLE_DOWNLOADER "/Users/shioshiota/goland/bin/sample_downloader")
    #    add_custom_target(
    #            ${SAMPLE} ALL
    #            COMMAND "${SAMPLE_DOWNLOADER}" "$ENV{ATCODER_USERNAME}" "$ENV{ATCODER_PASSWORD}" "${CONTEST_NAME}"
    #    )
endforeach (SOURCE)