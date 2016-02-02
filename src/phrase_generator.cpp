#include "phrase_generator.h"

#include "flat_list_parser.h"

#include <fstream>

phrase_generator::phrase_generator()
  : actions(), targets(), jokes()
{
  // Nothing else to do
}

phrase_generator::~phrase_generator()
{
  // Nothing else to do
}

phrase_generator& phrase_generator::load_action_strings(std::string filename)
{
  load_strings(filename, actions);
  return *this;
}

phrase_generator& phrase_generator::load_target_strings(std::string filename)
{
  load_strings(filename, targets);
  return *this;
}

phrase_generator& phrase_generator::load_joke_strings(std::string filename)
{
  load_strings(filename, jokes);
  return *this;
}

std::string phrase_generator::generate_phrase()
{
  return "";
}

bool phrase_generator::load_strings(std::string filename, list_randomizer& randomizer)
{
  // Open new file using filename
  std::ifstream in;
  in.open(filename);
  
  // Verify file opened successfully
  if (!in.good()) return false;
  
  std::vector<std::string> strings;
  flat_list_parser parser(in);
  
  for (const char* str = parser.next(); str != nullptr; str = parser.next())
  {
    strings.push_back(std::string(str));
    delete [] str;
  }
  
  randomizer.set_list_contents(strings);
  randomizer.shuffle();
  
  in.close();
}
