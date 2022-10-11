#ifndef INSERTION_SORT_PERSON_H
#define INSERTION_SORT_PERSON_H

#include <bits/stdc++.h>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string _name = "", int _age = 0);
    void setName(string);
    string getName() const;
    void setAge(int);
    int getAge() const;
    bool operator < (const Person&);
    bool operator > (const Person&);
    bool operator == (const Person&);
    bool operator >= (const Person&);
    bool operator <= (const Person&);
    virtual ~Person();
    friend ostream& operator << (ostream& print, const Person& obj) {
        print << "\n[PERSON] Name: " << obj.name << " Age: " << obj.age;
        return print;
    }
};

#endif //INSERTION_SORT_PERSON_H
