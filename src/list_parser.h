#ifndef __LIST_PARSER_H__
#define __LIST_PARSER_H__

#include <iosfwd>
#include <string>

class list_parser
{
public:
  list_parser(std::istream& in);
  virtual ~list_parser();
  
  virtual bool next(std::string& out) = 0;
  
protected:
  std::istream& in;
};

#endif /* defined(__LIST_PARSER_H__) */
