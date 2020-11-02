//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_QUADRENDERER_H
#define MINECRAFT_YISHIYU_EDITION_QUADRENDERER_H

#include <vector>

#include "../Model.h"
#include "../Maths/glm.h"
#include "../Shaders/BasicShader.h"
#include "../Texture/BasicTexture.h"

class Camera;

// 四边形渲染类
// 持有一个四边形模型,一个基础着色器,一个基础贴图
// 1. 可以添加模型的渲染位置(世界坐标)
// 2. 可以根据一个相机渲染出画面
class QuadRenderer {
public:
    QuadRenderer();

    void add(const glm::vec3 &position);

    void renderQuads(const Camera &camera);

private:
    std::vector<glm::vec3> m_quads;

    Model m_quadModel;
    BasicShader m_shader;
    BasicTexture m_basicTexture;
};

#endif //MINECRAFT_YISHIYU_EDITION_QUADRENDERER_H
