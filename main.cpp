#include <iostream>

/*
     * порождающие паттерны - гибкое создание объектов
     * структурные паттерны - построение связей между объектами
     * поведенческие паттерны - коммуникация между объектами
*/

#include <abstract_factory/abstract_factory.hpp>
#include <factory_method/factory_method.hpp>
#include <singleton/singleton.hpp>
#include <builder/builder.hpp>
#include <prototype/prototype.hpp>

std::ostream& tab(std::ostream &out) {
    return out << '\t';
}

void printName() {
    std::cout << DesignPatterns::Generative::Singleton::getInstance()->name() << std::endl;
}

void testFactory(const DesignPatterns::Generative::FurnitureFactory &factory) {
    DesignPatterns::Generative::Chair *chair = factory.createChair();
    DesignPatterns::Generative::Table *table = factory.createTable();

    std::cout << tab << "Chair type: " << chair->getChairType() << std::endl;
    std::cout << tab << "Table type: " << table->getTableType() << std::endl;

    delete table;
    delete chair;
}

void testFactoryMethod(const DesignPatterns::Generative::Creator &creator) {
    std::cout << tab << "Furniture type: " << creator.furnitureType() << std::endl;
}

void testBuilder() {
    DesignPatterns::Generative::Director director;
    DesignPatterns::Generative::Builder *builder = new DesignPatterns::Generative::ConcreteBuilder;
    director.setBuilder(builder);
    std::cout << "Minimal prodct:" << std::endl;
    director.buildMinimalViableProduct();
    builder->getProduct()->ListParts();
    std::cout << "Full prodct:" << std::endl;
    director.buildFullFeaturedProduct();
    builder->getProduct()->ListParts();
}

void testPrototype(const DesignPatterns::Generative::PrototypeFactory &prototype_reg) {
    DesignPatterns::Generative::Prototype *prototype = prototype_reg.createPrototype(DesignPatterns::Generative::Type::PROTOTYPE_1);
    prototype->method(100);
    delete prototype;
}

int main() {
    DesignPatterns::Generative::Singleton *singleton = DesignPatterns::Generative::Singleton::getInstance("Cat");
    std::cout << singleton->name() << std::endl;
    printName();

    std::cout << "Test Kitchen furniture factory:" << std::endl;
    DesignPatterns::Generative::FurnitureFactory *kitchenFurniture = new DesignPatterns::Generative::KitchenFurnitureFactory;
    testFactory(*kitchenFurniture);

    std::cout << "Test office furniture factory:" << std::endl;
    DesignPatterns::Generative::FurnitureFactory *officeFurniture = new DesignPatterns::Generative::OfficeFurnitureFactory;
    testFactory(*officeFurniture);

    std::cout << "Test Chair factory method:" << std::endl;
    DesignPatterns::Generative::Creator *chairCreator = new DesignPatterns::Generative::ChairCreator;
    testFactoryMethod(*chairCreator);

    std::cout << "Test Table factory method:" << std::endl;
    DesignPatterns::Generative::Creator *tableCreator = new DesignPatterns::Generative::TableCreator;
    testFactoryMethod(*tableCreator);

    std::cout << "Test Builder:" << std::endl;
    testBuilder();

    std::cout << "Test prototype:" << std::endl;
    DesignPatterns::Generative::PrototypeFactory prototype_reg;
    testPrototype(prototype_reg);

    return 0;
}
