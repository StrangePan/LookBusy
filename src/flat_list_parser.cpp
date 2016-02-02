#include "flat_list_parser.h"

#include <cstring>
#include <iostream>

flat_list_parser::flat_list_parser(std::istream& in)
  : list_parser(in)
{
  // Nothing else to do
}

flat_list_parser::~flat_list_parser()
{
  // Nothing else to do
}

const char* flat_list_parser::next()
{
  if (in.good())
  {
    std::string s;
    std::getline(in, s);
    
    char* c = new char[s.size()];
    std::strcpy(c, s.c_str());
    
    return c;
  }
  else
  {
    return nullptr;
  }
}
