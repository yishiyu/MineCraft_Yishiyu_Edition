//
// Created by Yishiyu on 2020/11/3.
//

#include "CubeRenderer.h"

#include <iostream>

#include "../Camera.h"
#include "../Maths/Matrix.h"

CubeRenderer::CubeRenderer() {
    m_basicTexture.loadFromFile("test");

    std::vector<GLfloat> vertexCoords
            {
                    //Back
                    1, 0, 0,
                    0, 0, 0,
                    0, 1, 0,
                    1, 1, 0,

                    //Front
                    0, 0, 1,
                    1, 0, 1,
                    1, 1, 1,
                    0, 1, 1,

                    //Right
                    1, 0, 1,
                    1, 0, 0,
                    1, 1, 0,
                    1, 1, 1,

                    //Left
                    0, 0, 0,
                    0, 0, 1,
                    0, 1, 1,
                    0, 1, 0,

                    //Top
                    0, 1, 1,
                    1, 1, 1,
                    1, 1, 0,
                    0, 1, 0,

                    //Bottom
                    0, 0, 0,
                    1, 0, 0,
                    1, 0, 1,
                    0, 0, 1.
            };

    std::vector<GLfloat> texCoords
            {
                    0, 1,
                    1, 1,
                    1, 0,
                    0, 0,

                    0, 1,
                    1, 1,
                    1, 0,
                    0, 0,

                    0, 1,
                    1, 1,
                    1, 0,
                    0, 0,

                    0, 1,
                    1, 1,
                    1, 0,
                    0, 0,

                    0, 1,
                    1, 1,
                    1, 0,
                    0, 0,

                    0, 1,
                    1, 1,
                    1, 0,
                    0, 0,
            };

    std::vector<GLuint> indices
            {
                    0, 1, 2,
                    2, 3, 0,

                    4, 5, 6,
                    6, 7, 4,

                    8, 9, 10,
                    10, 11, 8,

                    12, 13, 14,
                    14, 15, 12,

                    16, 17, 18,
                    18, 19, 16,

                    20, 21, 22,
                    22, 23, 20
            };

    m_cubeModel.addData(vertexCoords, texCoords, indices);
}

void CubeRenderer::add(const glm::vec3 &position) {
    m_quads.push_back(position);
}

void CubeRenderer::render(const Camera &camera) {
    glEnable(GL_CULL_FACE);


    m_shader.useProgram();
    m_cubeModel.bindVAO();
    m_basicTexture.bindTexture();

    m_shader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());

    for (auto &quad : m_quads) {
        m_shader.loadModelMatrix(makeModelMatrix({quad, {0, 0, 0}}));

        glDrawElements(GL_TRIANGLES, m_cubeModel.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }

    m_quads.clear();
}

