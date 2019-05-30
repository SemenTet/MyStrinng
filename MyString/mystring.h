#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>

namespace my_namespace
{
    class MyString
    {
    public:
        MyString();
        MyString(const MyString& string);
        MyString(const char* string);
//        MyString(MyString&& other) noexcept;


        MyString& operator= (const MyString &other);
        MyString& operator= (const char * string);
//        MyString& operator=(MyString&& other);

        friend void swap (MyString& l, MyString& r);

        MyString operator+ (const MyString &string);
        MyString operator+ (const char * string);

        MyString& operator+= (const MyString& string);
        MyString& operator+=(const char *sring);

        char& operator[](int indx);
        char  operator[](int indx) const;

        operator const char*() const;

        bool operator== (const MyString& string);
        bool operator== (const char* string);

        bool operator<=(const MyString& string);
        bool operator<= (const char* string);

        bool operator>=(const MyString& string);
        bool operator>=(const char *string );

        MyString& operator=(int number);
        int get_number();
        static MyString number(int num);

        MyString reverse();
        bool isEmpty();
        unsigned int size();
        const long set_hash() const;

        friend std::ostream& operator<<(std::ostream& stream , const MyString &string);
        friend std::istream& operator>> (std::istream& stream, const MyString &string);

        ~MyString();
    private:
        char* _data;
        mutable unsigned int _size;
        mutable long _hash;
        mutable bool _changed;
    };

    void swap(MyString &l, MyString &r);

    std::ostream &operator<<(std::ostream &stream, const MyString &string);
    std::istream &operator>>(std::istream &stream, const MyString &string);

} // of namespace my_namespace
