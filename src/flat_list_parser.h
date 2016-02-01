#ifndef __FLAT_LIST_PARSER_H__
#define __FLAT_LIST_PARSER_H__

#include "list_parser.h"

class flat_list_parser: public list_parser
{
public:
  flat_list_parser(std::istream& in);
  ~flat_list_parser();
  
  std::string next();
};

#endif /* defined(__FLAT_LIST_PARSER_H__) */
