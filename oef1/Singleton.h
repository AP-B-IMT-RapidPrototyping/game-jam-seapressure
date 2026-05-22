//
// Created by marsd on 26/03/2026.
//

#ifndef OEF1_SINGLETON_H
#define OEF1_SINGLETON_H

#pragma once
namespace game {
    template<typename T>
    class Singleton {
    public:
        static T &GetInstance() {
            static T instance{};
            return instance;
        }

        virtual ~Singleton() = default;

        Singleton(const Singleton &other) = delete;

        Singleton(Singleton &&other) = delete;

        Singleton &operator=(const Singleton &other) = delete;

        Singleton &operator=(Singleton &&other) = delete;

    protected:
        Singleton() = default;
    };
}
#endif //OEF1_SINGLETON_H
