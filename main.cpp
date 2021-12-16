#include <iostream>
#include "singleton.h"
#include "abstract_factory.h"

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

    return 0;
}
