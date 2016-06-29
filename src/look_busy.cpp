#include "look_busy.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
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
    
    if (rand() % 10 == 0)
    {
      // 1:5 chance for long-running process
      do_long_task();
    }
    else
    {
      // 4:5 chance of random-length short-term process
      do_short_task();
    }
  }
  
  return 0;
}

void look_busy::do_short_task()
{
  cout << pg.generate_phrase() << flush;
  this_thread::sleep_for(chrono::milliseconds(100 + rand() % (rand() % 5 == 0 ? 500 : 100)));
  cout << endl;
}

void look_busy::do_short_task_with_confirm()
{
  cout << pg.generate_phrase() << "..." << flush;
  this_thread::sleep_for(chrono::milliseconds(500 + rand() % 2000));
  cout << "done" << endl;
}

void look_busy::do_long_task()
{
  switch (rand() % 4)
  {
  case 0:
    do_long_task_with_spinner();
    break;
      
  case 1:
    do_long_task_with_progress_bar();
    break;
      
  case 2:
    do_long_task_with_progress_percent();
    break;
      
  case 3:
    do_long_task_with_dots();
    break;
      
  }
}

void look_busy::do_long_task_with_spinner()
{
  string s = pg.generate_phrase();
  int spins = 10 + rand() % 50;
  
  for (int i = 0; i < spins; i++)
  {
    cout << '\r' << s << " ";
    
    switch (i % 4)
    {
      case 0:
        cout << "\\";
        break;
        
      case 1:
        cout << "|";
        break;
        
      case 2:
        cout << "/";
        break;
        
      case 3:
        cout << "-";
        break;
    }
    
    cout << flush;
    
    this_thread::sleep_for(chrono::milliseconds(250));
  }
  
  cout << '\r' << s << "  " << endl;
}

void look_busy::do_long_task_with_progress_bar()
{
  string s = pg.generate_phrase();
  int steps = 15;
  int step_time = 25 + rand() % (rand() % 10 == 0 ? 9975 : 975);
  
  for (int step = 0; step <= steps; step++)
  {
    cout << '\r' << s << "  [";
    
    for (int i = 1; i <= steps; i++)
    {
      cout << (i <= step ? "=" : " ");
    }
    
    cout << "]" << flush;
    
    if (step < steps) this_thread::sleep_for(chrono::milliseconds(step_time));
  }
  
  cout << endl;
}

void look_busy::do_long_task_with_progress_percent()
{
  string s = pg.generate_phrase();
  int steps = 10 + rand() % (rand() % 10 == 0 ? 10000 : 700);
  
  cout << fixed << setprecision(1);
  
  for (int step = 0; step <= steps; step++)
  {
    cout << '\r' << s << ": " << right << setw(5)
         << (((float) step / (float) steps) * 100) << "%" << flush;
    this_thread::sleep_for(chrono::milliseconds(1000 / 60));

    //Randomly generate hang
    int hang = rand() % (100 + steps / 5);
    if( !hang )
    {
	//Generate a time for hanging (.25 - 3 seconds)
	int hang_time = rand() % 3000 + 250;
	this_thread::sleep_for(chrono::milliseconds(hang_time));
    }
  }
  
  cout << endl;
}

void look_busy::do_long_task_with_dots()
{
  string s = pg.generate_phrase();
  int steps = 2 + rand() % 15;
  
  cout << s;
  
  for (int step = 0; step <= steps; step++)
  {
    cout << "." << flush;
    this_thread::sleep_for(chrono::milliseconds(750));
  }
  
  cout << "done" << endl;
}
