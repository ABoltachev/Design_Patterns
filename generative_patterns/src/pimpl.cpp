#include <pimpl/pimpl_api.hpp>
#include <pimpl/pimpl.hpp>

PImplAPI::PImplAPI(const std::string &name) {
    pimpl = std::make_unique<PImpl>(name);
}

const std::string& PImplAPI::getName() const {
    return pimpl->name();
}
