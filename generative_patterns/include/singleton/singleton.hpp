#ifndef DESIGN_PATTERNS_SINGLETON_HPP
#define DESIGN_PATTERNS_SINGLETON_HPP

/*
    Singleton запрещает создание более одного экземляра класса
    Проблемы, которые решает:
         * Гарантирует наличие единственного экземпляра. Это полезно при получении доступа к общему ресурсу (файл, БД)
         * Глобальная точка доступа
*/

#include <string>

namespace DesignPatterns {
    namespace Generative {
        class Singleton {
        protected:
            std::string m_name;

            static Singleton *instance;

            Singleton(const std::string &name);
        public:
            Singleton(const Singleton &) = delete;

            void operator=(const Singleton &) = delete;

            static Singleton* getInstance(const std::string &name="");

            std::string& name();
        };
    }
}

#endif
