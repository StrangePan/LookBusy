#include "list_randomizer.h"

#include<algorithm>

list_randomizer::list_randomizer()
  : list(), curr(0)
{
  // Nothing else to do
}

list_randomizer::list_randomizer(const std::vector<std::string>& list)
  : list(list), curr(0)
{
  // Nothing else to do
}

list_randomizer::~list_randomizer()
{
  // Nothing else to do
}

void list_randomizer::set_list_contents(const std::vector<std::string>& list)
{
  this->list = list;
}

void list_randomizer::shuffle()
{
  std::random_shuffle(list.begin(), list.end());
  curr = 0;
}

std::string list_randomizer::next()
{
  if (list.empty()) return "";
  
  if (curr >= list.size()) shuffle();
  
  return list[curr++];
}
