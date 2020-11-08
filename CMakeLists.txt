cmake_minimum_required(VERSION 3.14)
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
        src/Model/Model.cpp src/Model/Model.h
        src/Camera.cpp src/Camera.h
        src/Application.cpp src/Application.h
        src/Texture/BasicTexture.cpp src/Texture/BasicTexture.h
        src/States/StatePlaying.cpp src/States/StatePlaying.h
        src/Shaders/BasicShader.cpp src/Shaders/BasicShader.h
        src/Shaders/Shader.cpp src/Shaders/Shader.h
        src/Shaders/ShaderLoader.cpp src/Shaders/ShaderLoader.h
        src/Renderer/RenderMaster.cpp src/Renderer/RenderMaster.h
        src/Renderer/QuadRenderer.cpp src/Renderer/QuadRenderer.h src/Player/Player.h src/Entity.h src/Player/Player.cpp src/Renderer/CubeRenderer.cpp src/Renderer/CubeRenderer.h src/Texture/TextureAtlas.h src/World/WorldConstants.h src/World/Block/BlockType.h src/Texture/TextureAtlas.cpp src/World/Block/BlockDict.h src/World/Block/BlockData.cpp src/World/Block/BlockData.h src/World/Block/Block.cpp src/World/Block/Block.h src/Mesh.h src/World/Block/BlockDB.cpp src/World/Block/BlockDB.h src/World/Block/BlockType.cpp src/Shaders/SectionShader.cpp src/Shaders/SectionShader.h src/Renderer/SectionRenderer.cpp src/Renderer/SectionRenderer.h src/Model/SectionModel.cpp src/Model/SectionModel.h src/World/Chunk/IChunk.h src/World/Chunk/Section.cpp src/World/Chunk/Section.h src/World/Chunk/Chunk.cpp src/World/Chunk/Chunk.h src/World/Chunk/SectionModelBuilder.cpp src/World/Chunk/SectionModelBuilder.h src/World/World.cpp src/World/World.h)

# 链接库文件
if (CMAKE_BUILD_TYPE MATCHES "Release")
    MESSAGE(STATUS "Release Edition")
    target_link_libraries(
            MineCraft_Yishiyu_Edition
            sfml-audio.lib
            sfml-graphics.lib
            sfml-network.lib
            sfml-system.lib
            sfml-window.lib
    )


elseif (CMAKE_BUILD_TYPE MATCHES "Debug")
    MESSAGE(STATUS "Debug Edition")
    target_link_libraries(
            MineCraft_Yishiyu_Edition
            sfml-audio-d.lib
            sfml-graphics-d.lib
            sfml-network-d.lib
            sfml-system-d.lib
            sfml-window-d.lib
    )

else ()
    message(FATAL_ERROR "Error while Linking")
endif ()

