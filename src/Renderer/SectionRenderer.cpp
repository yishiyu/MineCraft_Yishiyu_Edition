//
// Created by Yishiyu on 2020/11/6.
//

#include "SectionRenderer.h"
#include "World/Block/BlockDB.h"
#include "Camera.h"
#include "Model/SectionModel.h"

void SectionRenderer::add(const SectionModel &model) {
    m_sectionModels.push_back(&model);
}

void SectionRenderer::render(const Camera &camera) {
    m_sectionShader.useProgram();
    BlockDB::get().textureAtlas.bindTexture();

    m_sectionShader.loadProjectionViewMatrix(camera.getProjectionViewMatrix());
    for(auto &model : m_sectionModels){
        model->bindData();
        glDrawElements(GL_TRIANGLES, model->getIndicesCount(), GL_UNSIGNED_INT, nullptr);
    }

    m_sectionModels.clear();
}
