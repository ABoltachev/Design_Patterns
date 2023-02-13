#ifndef DESIGN_PATTERNS_BUILDER_HPP
#define DESIGN_PATTERNS_BUILDER_HPP

/*
    Builder пошаговое создание сложных объектов и использование одного и того же кода для разных представлений объектов
*/

#include <iostream>
#include <string>
#include <vector>

namespace DesignPatterns::Generative {
    class Product {
    public:
        std::vector<std::string> parts_;
        void ListParts() const;
    };

    class Builder{
    protected:
        Product *m_product;
    public:
        virtual ~Builder() = default;
        virtual void ProducePartA() const = 0;
        virtual void ProducePartB() const = 0;
        virtual void ProducePartC() const = 0;
        Product* getProduct();
        void reset();
    };

    class ConcreteBuilder : public Builder {
    public:
        ConcreteBuilder();

        ~ConcreteBuilder();

        void ProducePartA() const override;

        void ProducePartB() const override;

        void ProducePartC() const override;
    };

    class Director {
    private:
        Builder *m_builder;

    public:
        void setBuilder(Builder *builder);

        void buildMinimalViableProduct();
        
        void buildFullFeaturedProduct();
    };
}

#endif
