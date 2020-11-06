//
// Created by Yishiyu on 2020/11/6.
//

#include "SectionShader.h"

SectionShader::SectionShader():BasicShader("SectionVertex","SectionFragment"){
    getUniforms();
}

void SectionShader::getUniforms() {
    BasicShader::getUniforms();
}
