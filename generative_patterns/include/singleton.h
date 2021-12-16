#ifndef DESIGN_PATTERNS_SINGLETON_H
#define DESIGN_PATTERNS_SINGLETON_H

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
