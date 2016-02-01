/**
 * Start point for the LookBusy program. Instantiates an instance of the
 * main application object and kickstarts the program.
 */

#include "look_busy.h"

/**
 * Entry point for the program. Instantiates an instance of \ref look_busy and
 * 
 */
int main(int argc, char** argv)
{
  look_busy app;
  
  return app.run(argc, argv);
}
