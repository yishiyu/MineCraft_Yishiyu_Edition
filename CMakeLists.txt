cmake_minimum_required(VERSION 3.17)
project(MineCraft_Yishiyu_Edition)

set(CMAKE_CXX_STANDARD 14)

# 头文件搜索目录
include_directories(.)
include_directories(src)
include_directories(site-packages/include)

# 库文件包含目录
link_directories(site-packages/libs/GL site-packages/libs/SFML)

# 生成目标
add_executable(MineCraft_Yishiyu_Edition
        src/Main.cpp)

# 链接库文件
if (CMAKE_BUILD_TYPE MATCHES "Release")
    MESSAGE(STATUS "Release Edition")

    target_link_libraries(
            MineCraft_Yishiyu_Edition
            glew32.lib
            libsfml-audio.a
            libsfml-graphics.a
            libsfml-network.a
            libsfml-system.a
            libsfml-window.a
    )


elseif (CMAKE_BUILD_TYPE MATCHES "Debug")
    MESSAGE(STATUS "Debug Edition")

    target_link_libraries(
            MineCraft_Yishiyu_Edition
            glew32.lib
            libsfml-audio-d.a
            libsfml-graphics-d.a
            libsfml-network-d.a
            libsfml-system-d.a
            libsfml-window-d.a
    )

else ()
    message(FATAL_ERROR "Error while Linking")
endif ()

