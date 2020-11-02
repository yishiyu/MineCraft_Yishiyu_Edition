#version 330

// 基础片段着色器(直接根据纹理和坐标生成颜色)
// 输入: 二维纹理,二维坐标
// 输出: 颜色(四维向量)


out vec4 outColour;
in  vec2 passTextureCoord;

uniform sampler2D texSampler;

void main(){
    outColour = texture(texSampler, passTextureCoord);
}
