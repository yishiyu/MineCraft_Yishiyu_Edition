//
// Created by Yishiyu on 2020/11/3.
//

#ifndef MINECRAFT_YISHIYU_EDITION_CUBERENDERER_H
#define MINECRAFT_YISHIYU_EDITION_CUBERENDERER_H

#include <vector>
#include "src/Model/Model.h"
#include "../Maths/glm.h"
#include "../Shaders/BasicShader.h"
#include "../Texture/BasicTexture.h"
#include "../Texture/TextureAtlas.h"

class Camera;

// 方块渲染类
// 持有一个方块模型,一个基础着色器,一个基础贴图
// 1. 可以添加模型的渲染位置(世界坐标)
// 2. 可以根据一个相机渲染出画面
class CubeRenderer {
public:
    CubeRenderer();

    void add(const glm::vec3 &position);

    void render(const Camera &camera);

private:
    std::vector<glm::vec3> m_quads;

    Model m_cubeModel;
    BasicShader m_shader;
    BasicTexture m_basicTexture;

    TextureAtlas m_atlasTest;
};


#endif //MINECRAFT_YISHIYU_EDITION_CUBERENDERER_H
