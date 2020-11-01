//
// Created by Yishiyu on 2020/11/1.
//

#include "Random.h"

RandomSingleton& RandomSingleton::get()
{
    static RandomSingleton r;
    return r;
}

RandomSingleton::RandomSingleton()
{
    m_randomEngine.seed(std::time(nullptr));
    for (int i = 0; i < 5; i++)
        intInRange(i, i * 5);
}
