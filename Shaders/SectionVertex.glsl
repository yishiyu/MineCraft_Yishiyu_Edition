#version 330

// 小区块顶点着色器
// 输入: 顶点坐标,纹理坐标,投影视图矩阵
// 输出: 纹理坐标(,顶点坐标)

layout(location = 0) in vec3 inVertexPosition;
layout(location = 1) in vec2 inTextureCoord;

out vec2 passTextureCoord;

uniform mat4 projViewMatrix;

void main(){
    gl_Position = projViewMatrix * vec4(inVertexPosition, 1.0);
    // 直接传递纹理坐标
    passTextureCoord = inTextureCoord;
}
