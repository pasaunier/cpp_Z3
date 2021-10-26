#pragma once
#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include "demangle.hpp"

template<typename T>
std::string type_name2(T&& x)
{
    return demangle(typeid(x).name());
}

class ExceptionChaine : public std::exception
{
    const std::string type_n;
    const char* msg;
    
  public:
    ExceptionChaine(const std::string & exe)
      : type_n(exe)
    {
        std::stringstream err;
        std::cout << "Type déduit : " << type_n << std::endl;
        err << "Conversion en chaine impossible pour '" << type_n << "'";
        msg = err.str().c_str();
    }

    virtual const char* what() const throw() { return msg; };
};

template<typename T>
std::string chaine(T obj)
{
    throw ExceptionChaine(type_name2(obj));
}
