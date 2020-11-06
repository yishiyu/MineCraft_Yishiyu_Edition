//
// Created by Yishiyu on 2020/11/6.
//

#ifndef MINECRAFT_YISHIYU_EDITION_SECTIONSHADER_H
#define MINECRAFT_YISHIYU_EDITION_SECTIONSHADER_H

#include "BasicShader.h"

// 小区块渲染类
class SectionShader : public BasicShader {
public:
    SectionShader();
private:
    void getUniforms() override;

};


#endif //MINECRAFT_YISHIYU_EDITION_SECTIONSHADER_H
