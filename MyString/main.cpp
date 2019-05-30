#include <iostream>
#include "mystring.h"
using std::cin;
using std::cout;
using my_namespace::MyString;
int main()
{
    MyString a("lama ");
    const MyString b("star ");
    MyString c;
    c = a + b;
    a += b;
    std::cout << a<<std::endl;
    std::cout << c<<std::endl;
    std::cout << b<<std::endl;

    if(a == b)
        std::cout << "yep"<<std::endl;
    else
        std::cout << "ops"<<std::endl;

    if(!a.isEmpty())
        std::cout << "(a)string is not empty"<<std::endl;

    std::cout << a.reverse()<<std::endl;

    if (a >= b)
        std::cout << "good"<<std::endl;
    else
        std::cout << "not good"<<std::endl;

    std::cout <<  c.size() <<std::endl;
    try
    {
        std::cout << c[11];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    MyString k;
    k = -2;
    std::cout << std::endl << "the string by numb is: " << k << std::endl;
    return 0;
}
