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

bool flat_list_parser::next(std::string& out)
{
  std::string s;
  
  while (in.good() && s.empty())
  {
    std::getline(in, s);
  }
  
  if (!s.empty())
  {
    out = s;
    return true;
  }
  else
  {
    return false;
  }
}
