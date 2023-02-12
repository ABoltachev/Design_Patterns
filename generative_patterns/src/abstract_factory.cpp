#include <abstract_factory/abstract_factory.hpp>


namespace DesignPatterns {
    namespace Generative {
        std::string KitchenChair::getChairType() const {
            return "KitchenChair";
        }

        std::string KitchenTable::getTableType() const {
            return "KitchenTable";
        }

        Chair* KitchenFurnitureFactory::createChair() const {
            return new KitchenChair;
        }
        Table* KitchenFurnitureFactory::createTable() const {
            return new KitchenTable;
        }

        std::string OfficeChair::getChairType() const {
            return "OfficeChair";
        }

        std::string OfficeTable::getTableType() const {
            return "OfficeTable";
        }

        Chair* OfficeFurnitureFactory::createChair() const {
            return new OfficeChair;
        }
        Table* OfficeFurnitureFactory::createTable() const {
            return new OfficeTable;
        }
    }
}
