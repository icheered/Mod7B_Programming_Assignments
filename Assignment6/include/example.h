///
/// \file
/// Description of example.h file.
///

/*
 * Copyright license (in comments that doxygen does not parse)
 */

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <string>
#include <vector>

/// Abstract class with brief description.
///
/// More detailed text.
class Base
{
    /// A normal member taking two arguments, `a` and `b`, and returning an
    /// integer value.
    ///
    /// \param aaa An integer argument.
    /// \param sss A constant character pointer.
    /// \see Derived
    /// \return The test results
    int testMe(int aaa, const char *sss) {};

    /// A private data field
    int a;

    /// \brief Dtor.
    ///
    /// Dtor asdasdas sdfsf jksdf kjdf jksdhfskdjfhsk djfhsk dfs fhskf sdf
    /// sdkfksdf kjsdf ksjdf sdf
    ~Base() {}

public:
    /// A public virtual function
    ///
    /// \param a Explanation here.
    virtual void foo(int a) = 0;

};


/// Brief description.
///
/// More detailed text.
class Derived : public Base
{
public:
    /// Ctor
    Derived() {}

    /// public member
    int b;

    // no need to repeat documentation for overridden virtual functions (but possible)
    void foo(int a) override {};
};


/// Brief description
///
/// More detailed text.
class SomeClass
{
public:
    /// public member
    Derived der_one;
    /// public member
    Derived der_two;

    /// public member
    Base base_array[4];

    /// public member
    std::string str;
    /// public member
    std::vector<int> vec;

};


#endif /* EXAMPLE_H */
