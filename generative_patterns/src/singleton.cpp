#include "singleton.h"

namespace DesignPatterns {
    namespace Generative {
        Singleton *Singleton::instance = nullptr;

        Singleton::Singleton(const std::string &name) : m_name(name) {}

        Singleton* Singleton::getInstance(const std::string &name) {
            if (instance == nullptr) {
                instance = new Singleton(name);
            }
            return instance;
        }

        std::string& Singleton::name() {
            return m_name;
        }
    }
}
