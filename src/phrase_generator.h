#ifndef __PHRASE_GENERATOR_H__
#define __PHRASE_GENERATOR_H__

#include "list_randomizer.h"

#include <string>

class phrase_generator
{
public:
  phrase_generator();
  ~phrase_generator();
  
  phrase_generator& load_action_strings(std::string filename);
  phrase_generator& load_adjective_strings(std::string filename);
  phrase_generator& load_noun_strings(std::string filename);
  phrase_generator& load_joke_strings(std::string filename);
  std::string generate_phrase();
  
private:
  bool load_strings(std::string filename, list_randomizer& randomizer);
  
  list_randomizer actions;
  list_randomizer adjectives;
  list_randomizer nouns;
  list_randomizer jokes;
};

#endif /* define(__PHRASE_GENERATOR_H__) */
