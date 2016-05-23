#ifndef PERSON_HH
#define PERSON_HH

#include <string>

class Person  // A C++ class
{
public:
    Person(const std::string& name) : m_name(name), m_age(0) {}

    std::string name() const {return m_name;}

    unsigned int age() const {return m_age;}
    void setAge(unsigned int age) {m_age = age;}

    void speak();

private:
    std::string m_name;
    unsigned int m_age;
};


#endif // PERSON_HH

