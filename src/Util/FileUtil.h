//
// 文件工具类,提供一些静态函数来进行文件操作
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_FILEUTIL_H
#define MINECRAFT_YISHIYU_EDITION_FILEUTIL_H

#include <string>


// 文件工具类
class FileUtil {
public:
    // 以字符串的形式获取文件内容
    static std::string getFileContents(const std::string &filePath);
};


#endif //MINECRAFT_YISHIYU_EDITION_FILEUTIL_H
