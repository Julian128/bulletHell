/*
test file to understand inheritance and virtual functions
*/

#include <iostream>
#include <vector>


class baseClass
{
public:
    baseClass()
    {
        std::cout << "baseClass\n";
    };

    virtual void func() = 0;

};


class derivedClassA : public baseClass
{
public:

    derivedClassA()
    {
        std::cout << "derivedClass\n";
    }

    void func() override
    {
        std::cout << "derivedClassA::func()";
    }
};

class derivedClassB : public baseClass
{
public:

    derivedClassB()
    {
        std::cout << "derivedClass\n";
    }

    void func() override
    {
        std::cout << "derivedClassB::func()";
    }
};



int main()
{


    // create std::vector that holds pointers to derivedClassA and derivedClassB
    std::vector<baseClass*> vec;

    // add derivedClassA and derivedClassB to the vector
    vec.push_back(new derivedClassA);
    vec.push_back(new derivedClassB);

    // call func() for each element in the vector
    for (auto &i : vec)
    {
        i->func();
    }





}
