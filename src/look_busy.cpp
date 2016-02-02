#include "look_busy.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

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
  srand(time(0));
  
  pg.load_action_strings("res/actions.txt");
  pg.load_adjective_strings("res/adjectives.txt");
  pg.load_noun_strings("res/nouns.txt");
  pg.load_joke_strings("res/eastereggs.txt");
  
  while (true)
  {
    string phrase = pg.generate_phrase();
    
    if (rand() % 5 > 0)
    {
      // 1:5 chance for long-running process
    }
    else
    {
      // 4:5 chance of random-length short-term process
    }
    
    cout << pg.generate_phrase() << endl;
    this_thread::sleep_for(chrono::seconds(2));
  }
  
  return 0;
}
