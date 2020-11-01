//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_BASICTEXTURE_H
#define MINECRAFT_YISHIYU_EDITION_BASICTEXTURE_H

#include <GL/glew.h>
#include <string>

#include "../Util/NonCopyable.h"

class BasicTexture
{
public:
    BasicTexture() = default;
    BasicTexture(const std::string& file);

    ~BasicTexture();

    void loadFromFile (const std::string& file);

    void bindTexture() const;


private:
    GLuint m_id;
};

#endif //MINECRAFT_YISHIYU_EDITION_BASICTEXTURE_H
