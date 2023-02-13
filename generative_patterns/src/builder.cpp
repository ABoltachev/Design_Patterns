#include <builder/builder.hpp>

namespace DesignPatterns::Generative {
    void Product::ListParts() const {
        std::cout << "Product parts: ";
        for (size_t i = 0; i < parts_.size(); i++) {
            if(parts_[i] == parts_.back()) {
                std::cout << parts_[i];
            }else{
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }

    ConcreteBuilder::ConcreteBuilder() {
        reset();
    }

    ConcreteBuilder::~ConcreteBuilder(){
        delete m_product;
    }

    void Builder::reset() {
        m_product = new Product();
    }

    void ConcreteBuilder::ProducePartA() const {
        m_product->parts_.push_back("PartA1");
    }

    void ConcreteBuilder::ProducePartB() const {
        m_product->parts_.push_back("PartB1");
    }

    void ConcreteBuilder::ProducePartC() const {
        m_product->parts_.push_back("PartC1");
    }

    Product* Builder::getProduct() {
        Product *result = m_product;
        reset();
        return result;
    }

    void Director::setBuilder(Builder *builder) {
        m_builder = builder;
    }

    void Director::buildMinimalViableProduct() {
        m_builder->ProducePartA();
    }

    void Director::buildFullFeaturedProduct() {
        m_builder->ProducePartA();
        m_builder->ProducePartB();
        m_builder->ProducePartC();
    }
}
