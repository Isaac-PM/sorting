#include "Person.h"

Person::Person(string _name, int _age) {
    this->name = _name;
    this->age = _age;
}

void Person::setName(string _name) {
    this->name = _name;
}

string Person::getName() const {
    return this->name;
}

void Person::setAge(int _age) {
    this->age = _age;
}

int Person::getAge() const {
    return this->age;
}

bool Person::operator < (const Person& obj) {
    return this->age < obj.age;
}

bool Person::operator > (const Person& obj) {
    return this->age > obj.age;
}

bool Person::operator == (const Person& obj) {
    return this->age == obj.age;
}

bool Person::operator >= (const Person& obj) {
    return this->age >= obj.age;
}

bool Person::operator <= (const Person& obj) {
    return this->age <= obj.age;
}

Person::~Person() {
    // cout << "\n[Person::~Person()] Deleted.";
}