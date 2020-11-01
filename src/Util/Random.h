//
// 定义了一个普通随机数类和一个单例随机数类
// Created by Yishiyu on 2020/11/1.
//

#ifndef MINECRAFT_YISHIYU_EDITION_RANDOM_H
#define MINECRAFT_YISHIYU_EDITION_RANDOM_H

#include <random>
#include <ctime>
#include "Singleton.h"

// 使用mersenne_twister_engine(梅森旋转算法)生成均匀分布的随机数
// https://docs.microsoft.com/zh-cn/cpp/standard-library/mersenne-twister-engine-class?view=msvc-160
template<typename REngine = std::mt19937>
class Random {
public:
    Random() {
        // 初始化随机数引擎
        m_randomEngine.seed(std::time(nullptr));
        for (int i = 0; i < 5; i++)
            intInRange(i, i * 5);
    }

    template<typename T>
    T intInRange(T low, T high) {
        // 编译期判定参数是否为整数
        static_assert(std::is_integral<T>::value, "Not integral type!");
        // 生成[下界,上界)内的均匀分布整数 的分布对象
        std::uniform_int_distribution<T> dist(low, high);
        // 结合随机数分布和随机数引擎生成随机数
        return dist(m_randomEngine);
    }

private:
    // 梅森旋转算法 随机数引擎
    REngine m_randomEngine;
};

// 单例模式的随机数类
class RandomSingleton : public Singleton {
public:
    static RandomSingleton &get();

    template<typename T>
    T intInRange(T low, T high) {
        static_assert(std::is_integral<T>::value, "Not integral type!");
        std::uniform_int_distribution<T> dist(low, high);
        return dist(m_randomEngine);
    }

private:
    RandomSingleton();

    std::mt19937 m_randomEngine;
};


#endif //MINECRAFT_YISHIYU_EDITION_RANDOM_H
