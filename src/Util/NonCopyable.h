//
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_NONCOPYABLE_H
#define MINECRAFT_YISHIYU_EDITION_NONCOPYABLE_H

// 可以阻止子类自动生成拷贝构造函数和相对应的=操作符
// 由于自动生成的移动构造函数也会用到基类的复制构造函数,所以会报错
// 但是可以手动实现子类的移动构造函数
class NonCopyable {
public:
    NonCopyable() = default;

    NonCopyable(const NonCopyable &) = delete;

    NonCopyable &operator=(const NonCopyable &) = delete;
};


#endif //MINECRAFT_YISHIYU_EDITION_NONCOPYABLE_H
