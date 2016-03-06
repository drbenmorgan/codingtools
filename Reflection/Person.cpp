#include "Person.hpp"
#include <iostream>

class Person  // A C++ class
{
public:
    Person(const std::string& name) : m_name(name), m_age(0) {}

    std::string name() const {return m_name;}

    unsigned int age() const {return m_age;}
    void setAge(unsigned int age) {m_age = age;}

    void speak() {
        std::cout << "Hi! My name is " << m_name << " and I'm " << m_age << " years old." << std::endl;
    }

private:
    std::string m_name;
    unsigned int m_age;
};

#include "ponder/classbuilder.hpp"
#include "ponder/class.hpp"
#include "ponder/pondertype.hpp"

PONDER_TYPE(Person) // declare type


void declare() // register details (once)
{
    ponder::Class::declare<Person>("Person")
        .constructor<std::string>()
        .property("name", &Person::name)
        .property("age", &Person::age, &Person::setAge)
        .function("speak", &Person::speak)
        ;
}

