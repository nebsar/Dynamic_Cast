/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 13, 2018, 1:36 AM
 */

#include <iostream>
#include <exception>
#include <ratio>

class Base {
public:

    virtual void print() {
        std::cout << "This is Base class\n";
    }

};

class Derived1 : public Base {
public:

    void print() override {
        std::cout << "This is Derived1 class\n";
    }
};

class Derived2 : public Base {
public:

    void print() override {
        std::cout << "This is Derived2 class\n";
    }
};

int main() {

    Derived1 d1;

    Base* bp = dynamic_cast<Base*> (&d1);

    bp->print();

    Derived2* d2 = dynamic_cast<Derived2*> (bp);

    Derived1* d3 = dynamic_cast<Derived1*> (bp);

    if (d3 == nullptr) {
        std::cout << "This is nullptr \n";
    } else
        std::cout << "This is NOT NULL \n";


    try {
        Derived1& d4 = dynamic_cast<Derived1&> (d1);
    } catch (std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }
    return 0;
}

