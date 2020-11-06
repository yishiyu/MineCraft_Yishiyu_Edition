//
// Created by Yishiyu on 2020/11/1.
//

#include "QuadRenderer.h"

#include <iostream>

#include "../Camera.h"
#include "../Maths/Matrix.h"

QuadRenderer::QuadRenderer() {
    m_basicTexture.loadFromFile("test");

    m_quadModel.addData(
            {{
                     -0.5, 0.5, 0,
                     0.5, 0.5, 0,
                     0.5, -0.5, 0,
                     -0.5, -0.5, 0,
             },
             {
                     0,   1,
                     1,   1,
                     1,   0,
                     0,   0,
             },
             {
                     0,   1,   2,
                     2,   3,   0
             }});
}

void QuadRenderer::add(const glm::vec3 &position) {
    m_quads.push_back(position);
}

void QuadRenderer::renderQuads(const Camera &camera) {
    // 绑定模型的VAO
    m_shader.useProgram();
    m_quadModel.bindVAO();
    m_basicTexture.bindTexture();

    // 生成相机对应的投影视图矩阵并传给着色器
    m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());

    // 依次在每一个位置上渲染四边形
    for (auto &quad : m_quads) {
        m_shader.loadModelMatrix(makeModelMatrix({quad, {0, 0, 0}}));
        glDrawElements(GL_TRIANGLES, m_quadModel.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }

    m_quads.clear();
}

