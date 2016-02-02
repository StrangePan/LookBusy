#ifndef __LIST_RANDOMIZER_H__
#define __LIST_RANDOMIZER_H__

#include<vector>
#include<string>

class list_randomizer
{
public:
  list_randomizer();
  list_randomizer(const std::vector<std::string>& list);
  ~list_randomizer();
  
  void set_list_contents(const std::vector<std::string>& list);
  void shuffle();
  std::string next();
  
private:
  std::vector<std::string> list;
  int curr;
};

#endif /* defined(__LIST_RANDOMIZER_H__) */
