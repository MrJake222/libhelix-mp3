cmake_minimum_required(VERSION 3.9)

project(helixmp3)

FILE(GLOB HelixMP3_real_src
        real/*.c)


add_library(${PROJECT_NAME}
        ${HelixMP3_real_src}
        mp3dec.c
        mp3tabs.c)

target_include_directories(${PROJECT_NAME} PUBLIC
        pub)


# static allocations
set(PROJ_STATIC ${PROJECT_NAME}_static)
add_library(${PROJ_STATIC})
target_sources(${PROJ_STATIC} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/static/helix_static.c)
target_link_libraries(${PROJ_STATIC} PUBLIC
        helixmp3)
target_include_directories(${PROJ_STATIC} PUBLIC
        static)