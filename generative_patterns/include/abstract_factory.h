#ifndef DESIGN_PATTERNS_ABSTRACT_FACTORY_H
#define DESIGN_PATTERNS_ABSTRACT_FACTORY_H

#include <string>

namespace DesignPatterns {
    namespace Generative {
        // Интерфейсы продуктов и фабрики

        class Chair {
        public:
            virtual ~Chair() = default;
            virtual std::string getChairType() = 0;
        };

        class Table {
        public:
            virtual ~Table() = default;
            virtual std::string getTableType() = 0;
        };

        class FurnitureFactory {
        public:
            virtual Chair* createChair() const = 0;
            virtual Table* createTable() const = 0;
        };

        // Реализация кухонной фурнитуры

        class KitchenChair : public Chair {
        public:
            virtual std::string getChairType() override;
        };

        class KitchenTable : public Table {
        public:
            virtual std::string getTableType() override;
        };

        class KitchenFurnitureFactory : public FurnitureFactory {
        public:
            virtual Chair* createChair() const override;
            virtual Table* createTable() const override;
        };

        // Реализация офисной фурнитуры

        class OfficeChair : public Chair {
        public:
            virtual std::string getChairType() override;
        };

        class OfficeTable : public Table {
        public:
            virtual std::string getTableType() override;
        };

        class OfficeFurnitureFactory : public FurnitureFactory {
        public:
            virtual Chair* createChair() const override;
            virtual Table* createTable() const override;
        };
    }
}
#endif
