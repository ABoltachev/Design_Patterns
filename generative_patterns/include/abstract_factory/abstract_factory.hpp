#ifndef DESIGN_PATTERNS_ABSTRACT_FACTORY_HPP
#define DESIGN_PATTERNS_ABSTRACT_FACTORY_HPP

/*
    AbstractFactory создает семейства связанных объектов без поривязки к конкретным классам
    Проблемы, которые решает:
         * Создание объектов связанных чем-либо с другими объектами того же семейства
*/

#include <string>

namespace DesignPatterns {
    namespace Generative {
        // Интерфейсы продуктов и фабрики

        class Chair {
        public:
            virtual ~Chair() = default;
            virtual std::string getChairType() const = 0;
        };

        class Table {
        public:
            virtual ~Table() = default;
            virtual std::string getTableType() const = 0;
        };

        class FurnitureFactory {
        public:
            virtual Chair* createChair() const = 0;
            virtual Table* createTable() const = 0;
        };

        // Реализация кухонной фурнитуры

        class KitchenChair : public Chair {
        public:
            virtual std::string getChairType() const override;
        };

        class KitchenTable : public Table {
        public:
            virtual std::string getTableType() const override;
        };

        class KitchenFurnitureFactory : public FurnitureFactory {
        public:
            virtual Chair* createChair() const override;
            virtual Table* createTable() const override;
        };

        // Реализация офисной фурнитуры

        class OfficeChair : public Chair {
        public:
            virtual std::string getChairType() const override;
        };

        class OfficeTable : public Table {
        public:
            virtual std::string getTableType() const override;
        };

        class OfficeFurnitureFactory : public FurnitureFactory {
        public:
            virtual Chair* createChair() const override;
            virtual Table* createTable() const override;
        };
    }
}
#endif
