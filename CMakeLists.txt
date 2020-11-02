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
        src/Main.cpp src/Maths/glm.h
        src/Context.cpp src/Context.h
        src/States/StateBase.h src/glad.c
        src/Maths/Matrix.cpp src/Maths/Matrix.h
        src/Util/NonCopyable.h src/Util/Singleton.h
        src/Util/Random.cpp src/Util/Random.h
        src/Util/FileUtil.cpp src/Util/FileUtil.h
        src/Model.cpp src/Model.h
        src/Camera.cpp src/Camera.h
        src/Application.cpp src/Application.h
        src/Texture/BasicTexture.cpp src/Texture/BasicTexture.h
        src/States/StatePlaying.cpp src/States/StatePlaying.h
        src/Shaders/BasicShader.cpp src/Shaders/BasicShader.h
        src/Shaders/Shader.cpp src/Shaders/Shader.h
        src/Shaders/ShaderLoader.cpp src/Shaders/ShaderLoader.h
        src/Renderer/RenderMaster.cpp src/Renderer/RenderMaster.h
        src/Renderer/QuadRenderer.cpp src/Renderer/QuadRenderer.h src/Player/Player.h src/Entity.h)

# 链接库文件
if (CMAKE_BUILD_TYPE MATCHES "Release")
    MESSAGE(STATUS "Release Edition")

    target_link_libraries(
            MineCraft_Yishiyu_Edition
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
            libsfml-audio-d.a
            libsfml-graphics-d.a
            libsfml-network-d.a
            libsfml-system-d.a
            libsfml-window-d.a
    )

else ()
    message(FATAL_ERROR "Error while Linking")
endif ()

