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
  char* c = nullptr;
  std::string s;
  
  while (in.good() && s.empty())
  {
    std::getline(in, s);
  }
  
  if (!s.empty())
  {
    c = new char[s.size()];
    std::strcpy(c, s.c_str());
  }
  
  return c;
}
