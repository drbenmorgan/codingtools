#include "Person.hpp"
#include <iostream>

void Person::speak() {
  std::cout << "Hi! My name is " << m_name << " and I'm " << m_age << " years old." << std::endl;
}


