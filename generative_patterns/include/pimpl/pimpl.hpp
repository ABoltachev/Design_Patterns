#ifndef DESIGN_PATTERNS_PIMPL_HPP
#define DESIGN_PATTERNS_PIMPL_HPP

#include <string>

class PImpl {
protected:
    std::string m_name;
public:
    PImpl() = default;

    PImpl(const std::string &name) : m_name(name) {};

    std::string& name() {
        return m_name;
    }
};

#endif
