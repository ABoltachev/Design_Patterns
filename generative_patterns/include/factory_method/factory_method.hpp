#ifndef DESIGN_PATTERNS_FACTORY_METHOD_HPP
#define DESIGN_PATTERNS_FACTORY_METHOD_HPP

/*
    FactoryMethod определяет общий интерфейс для создания объектов в суперклассе, позволяя подклассам изменять тип создаваемых объектов
    Проблемы, которые решает:
         * Добавление в программу новых классов схожих внешне с другими без переписывания кучи кода
*/

#include <string>

namespace DesignPatterns {
    namespace Generative {
        // Интерфейс продукта и создателя

        class Furniture {
        public:
            virtual ~Furniture() = default;
            virtual std::string getFurnitureType() const = 0;
        };

        class Creator {
        public:
            virtual ~Creator() = default;
            virtual Furniture* factoryMethod() const = 0;

            std::string furnitureType() const;
        };

        // Реализация фурнитуры и создателей

        class ChairM : public Furniture {
        public:
            virtual std::string getFurnitureType() const override;
        };

        class TableM : public Furniture {
        public:
            virtual std::string getFurnitureType() const override;
        };

        class ChairCreator : public Creator {
        public:
            virtual Furniture* factoryMethod() const override;
        };

        class TableCreator : public Creator {
        public:
            virtual Furniture* factoryMethod() const override;
        };
    }
}
#endif
