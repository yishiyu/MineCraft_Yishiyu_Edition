#version 330

// 基础顶点着色器
// 输入: 顶点坐标,纹理坐标,模型矩阵,投影视图矩阵
// 输出: 纹理坐标

layout(location = 0) in vec3 inVertexPosition;
layout(location = 1) in vec2 inTextureCoord;

out vec2 passTextureCoord;

uniform mat4 projViewMatrix;
uniform mat4 modelMatrix;

void main(){
    // 坐标 = 投影矩阵 * 观察矩阵 * 模型矩阵 * 局部坐标
    // 其中观察矩阵(view matrix)和投影矩阵(projection matrix)合并为投影视图矩阵(projViewMatrix)
    gl_Position = projViewMatrix * modelMatrix * vec4(inVertexPosition, 1.0);
    // 直接传递纹理坐标
    passTextureCoord = inTextureCoord;
}
