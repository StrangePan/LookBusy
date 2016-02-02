#include "look_busy.h"

#include <iostream>
#include <thread>
#include <chrono>

look_busy::look_busy()
  : pg()
{
  // Nothing else to do
}

look_busy::~look_busy()
{
  // Nothing else to do
}

int look_busy::run(int argc, char** argv)
{
  pg.load_action_strings("res/actions.txt");
  pg.load_adjective_strings("res/adjectives.txt");
  pg.load_noun_strings("res/nouns.txt");
  pg.load_joke_strings("res/eastereggs.txt");
  
  while (true)
  {
    std::cout << pg.generate_phrase() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
  
  return 0;
}
