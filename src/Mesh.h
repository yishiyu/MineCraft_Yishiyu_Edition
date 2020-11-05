//
// Created by Yishiyu on 2020/11/5.
//

#ifndef MINECRAFT_YISHIYU_EDITION_MESH_H
#define MINECRAFT_YISHIYU_EDITION_MESH_H

#include <vector>
#include <glad/glad.h>

// Mesh 类封装了渲染所需的信息:
// 顶点坐标,纹理坐标,渲染下标(EBO)
struct Mesh {
    std::vector<GLfloat> vertexPosition;
    std::vector<GLfloat> textureCoord;
    std::vector<GLuint> indices;
};

#endif //MINECRAFT_YISHIYU_EDITION_MESH_H
