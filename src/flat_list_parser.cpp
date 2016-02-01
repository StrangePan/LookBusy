#include "flat_list_parser.h"

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

std::string flat_list_parser::next()
{
  if (in.good())
  {
    std::string s;
    std::getline(in, s);
    return s;
  }
  else
  {
    return nullptr;
  }
}
