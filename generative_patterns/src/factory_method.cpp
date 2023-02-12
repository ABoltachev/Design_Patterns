#include <factory_method/factory_method.hpp>

namespace DesignPatterns {
    namespace Generative {
        std::string Creator::furnitureType() const {
            Furniture *furniture = factoryMethod();

            std::string res = furniture->getFurnitureType();
            delete furniture;
            return res;
        }

        std::string ChairM::getFurnitureType() const {
            return "It's Chair";
        }

        std::string TableM::getFurnitureType() const {
            return "It's Table";
        }

        Furniture* ChairCreator::factoryMethod() const {
            return new ChairM();
        }

        Furniture* TableCreator::factoryMethod() const {
            return new TableM();
        }
    }
}
