#include "abstract_factory.h"


namespace DesignPatterns {
    namespace Generative {
        std::string KitchenChair::getChairType() {
            return "KitchenChair";
        }

        std::string KitchenTable::getTableType() {
            return "KitchenTable";
        }

        Chair* KitchenFurnitureFactory::createChair() const {
            return new KitchenChair;
        }
        Table* KitchenFurnitureFactory::createTable() const {
            return new KitchenTable;
        }

        std::string OfficeChair::getChairType() {
            return "OfficeChair";
        }

        std::string OfficeTable::getTableType() {
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
