#include "mystring.h"
#include <exception>
#include <cmath>
#include <sstream>
#include <utility>
#include <algorithm>
using std::runtime_error;
using my_namespace::MyString;

MyString::MyString()
{
    this->_size=0;
    std::cout<<"&&&&&simple constructor&&&&&"<<std::endl;
    this->_data = new char[1];
    this->_data[0] ='\0';
    this->_hash = 0;
    this ->_changed = true;
}

MyString::~MyString()
{
    delete[] this->_data;
    this-> _size = 0;
}

MyString::MyString(const MyString &string)
    : _data(new char[string._size + 1])
    , _size(string._size)
{
    std::cout<<"cp";
    strcpy(this->_data, string._data);
}

MyString::MyString(const char* string)
    : _data(new char[strlen(string) + 1])
    , _size(strlen(string))
{
    std::cout<<"S";
    strcpy(this->_data, string);
}

//MyString::MyString(my_namespace::MyString &&other)
//{
//    _data = other._data;
//    other._data = nullptr;
//}

//my_namespace::MyString &MyString::operator=(my_namespace::MyString &&other)
//{
//    swap (*this, other);
//    return *this;
//}

MyString& MyString::operator= (const MyString &other)
{
    std::cout<<"=";
    MyString tmp(other._data);
    swap(*this, tmp);
    return *this;
}

MyString& MyString::operator= (const char* chars)
{
    std::cout<<"&&&&copy = oper for string&&&&"<<std::endl;
    MyString tmp(chars);
    swap(*this, tmp);
    return *this;
}

MyString& MyString::operator=(int num) {
    std::cerr << "N";
    std::stringstream ss;
    ss << num;
    MyString res(ss.str().c_str());
    std::cerr << "N";
    swap(*this, res);
    std::cerr << "N";

    return *this;
}

unsigned int MyString::size()
{
     return this->_size;
}

bool MyString::isEmpty()
{
    std::cout<<"&&&&isempty check&&&&"<<std::endl;
    return !this->_size;
}

MyString MyString::reverse()
{
    std::cout<<"&&& reverse: ";
    char* new_data = new char[_size + 1];
    new_data[_size] = '\0';
    for (int i = 0; i < _size; ++i)
        new_data[i] = _data[_size - 1 - i];
    delete[] _data;
    _data = new_data;

    this->_changed=true;
    this->set_hash();
    return *this;
}

MyString MyString::operator+ (const MyString &other)
{
    std::cout <<"&&&&simple operator +&&&&"<<std::endl;

    MyString sum ;
    sum._size = this->_size+other._size;
    sum._data = new char[sum._size];
    strcpy(&sum._data[0], &this->_data[0]);
    strcpy(&sum._data[this->size()], &other._data[0]);
    sum._data[sum._size] = '\0';

    sum._changed=true;
    sum.set_hash();
    return sum;
}

MyString MyString::operator+(const char * other_chars)
{
    std::cout<<"&&&&string operator +&&&&"<<std::endl;
    MyString sum ;
    sum._size = this->_size+strlen(other_chars);
    sum._data = new char[sum._size + 1];
    strcpy(&sum._data[0], &this->_data[0]);
    strcpy(&sum._data[this->size()], &other_chars[0]);
    sum._data[sum._size] = '\0';

    sum._changed=true;
    sum.set_hash();
    return sum;
}

MyString& MyString::operator+=(const MyString& other)
{
    std::cout <<"&&&&simple operator +&&&&"<<std::endl;
    *this = *this + other ;
    this->_changed = true;
    this->set_hash();
    return *this;
}

MyString& MyString::operator+=(const char *other)
{
    std::cout <<"&&&&&string operator +=&&&&&"<<std::endl;
    MyString str(other);
    *this = *this + str;
    this->_changed = true;
    this->set_hash();
    return *this;
}

bool MyString::operator== (const MyString& string)
{
    std::cout <<"&&&&simple operator ==&&&&"<<std::endl;
    return !strcmp(this->_data, string._data);
}

bool MyString::operator== (const char* other_chars)
{
    std::cout <<"&&&&string operator ==&&&&"<<std::endl;
    return !strcmp(this->_data, other_chars);
}

char& MyString::operator[](int indx)
{
    if(indx < 0 || indx >= this->_size) {
        throw runtime_error("there is no spot in string with this index \n");
    }
    return this->_data[indx];
}

char MyString::operator[](int indx)const
{
    if(indx < 0 || indx >= this->_size) {
        throw runtime_error("there is no spot in string with this index \n");
    }
    return this->_data[indx];
}

MyString::operator const char*() const {
    return this->_data;
}

const long MyString::set_hash() const
{
    if(!this->_changed)
        return this->_hash;

    this->_hash = 0;
    for(int i = 0; i < this->_size; ++i) {
        this->_hash += this->_data[i];
    }

    this->_changed = false;
    std::cout<<"&&&&&hash: ";
    return this->_hash;
}

bool MyString :: operator<=(const MyString& string)
{
    return strlen(this->_data) <= strlen(string._data);
}

bool MyString:: operator<= (const char* string)
{
    return strlen(this->_data) <= strlen(string);

}

bool MyString:: operator>=(const MyString& string)
{
    return strlen (this->_data) >= strlen(string._data);
}

bool MyString :: operator>=(const char *string )
{
    return strlen (this->_data) >= strlen(string);
}

int MyString::get_number() {
//    int result = 0;
//    bool positive = true;
//    int start_pos = 0;
//    if(this->_data[0]=='-') {
//           positive =false;
//           start_pos++;
//    }

//    for(int i = start_pos; i < this->_size; ++i)
//    {
//        char digit = this->_data[i];
//        if (digit >= '0' && digit <= '9') {
//            result = result * 10 + (digit - '0');
//        } else {
//            throw std::logic_error("cannot convert that string to number");
//        }
//    }

//    if (!positive)
//        result *= -1;

//    return result;
    return atoi(_data);
}

MyString MyString::number(int num)
{
    std::stringstream ss;
    ss << num;
    MyString res(ss.str().c_str());
    return res;
}

std::ostream& my_namespace::operator<<(std::ostream &stream, const MyString &string)
{
    stream << string._data;
    return stream;
}

std::istream& my_namespace::operator>>(std::istream &stream, const MyString &string)
{
    stream >> string._data;
    return stream;
}

void my_namespace::swap(my_namespace::MyString &l, my_namespace::MyString &r)
{
    using std::swap;
    swap (l._data , r._data);
    swap (l._size, r._size);
}
