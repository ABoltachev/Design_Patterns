#ifndef DESIGN_PATTERNS_PIMPL_API_HPP
#define DESIGN_PATTERNS_PIMPL_API_HPP

#include <memory>

class PImpl;

class PImplAPI {
private:
    std::unique_ptr<PImpl> pimpl;
public:
    PImplAPI(const std::string &name);

    const std::string& getName() const;
};

#endif
