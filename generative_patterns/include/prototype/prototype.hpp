#ifndef DESIGN_PATTERNS_PROTOTYPE_HPP
#define DESIGN_PATTERNS_PROTOTYPE_HPP

/*
    Prototype копирование объекта, без знания реализации
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace DesignPatterns::Generative {
    enum class Type {
        PROTOTYPE_1,
        PROTOTYPE_2,
    };

    class Prototype {
    protected:
        std::string m_prototype_name;
        float m_prototype_field;

    public:
        Prototype() {}
        Prototype(const std::string &prototype_name) : m_prototype_name(prototype_name) {}
        virtual ~Prototype() {}
        virtual Prototype* clone() const = 0;
        virtual void method(float prototype_field) {
            m_prototype_field = prototype_field;
            std::cout << "Call Method from " << m_prototype_name << " with field : " << prototype_field << std::endl;
        }
    };

    class ConcretePrototype1 : public Prototype {
    private:
        float m_concrete_prototype_field;

    public:
        ConcretePrototype1(std::string prototype_name, float concrete_prototype_field)
            : Prototype(prototype_name), m_concrete_prototype_field(concrete_prototype_field) {}

        Prototype* clone() const override {
            return new ConcretePrototype1(*this);
        }
    };

    class ConcretePrototype2 : public Prototype {
    private:
        float m_concrete_prototype_field;

    public:
        ConcretePrototype2(std::string prototype_name, float concrete_prototype_field)
            : Prototype(prototype_name), m_concrete_prototype_field(concrete_prototype_field) {
        }
        Prototype *clone() const override {
            return new ConcretePrototype2(*this);
        }
    };

    class PrototypeFactory {
    private:
        std::unordered_map<Type, Prototype*> m_prototypes;

    public:
        PrototypeFactory() {
            m_prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
            m_prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
        }

        ~PrototypeFactory() {
            delete m_prototypes[Type::PROTOTYPE_1];
            delete m_prototypes[Type::PROTOTYPE_2];
        }

        Prototype *createPrototype(Type type) const {
            return m_prototypes.at(type)->clone();
        }
    };
}

#endif
