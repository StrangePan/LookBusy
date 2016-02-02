#ifndef __LOOK_BUSY_H__
#define __LOOK_BUSY_H__

#include "application.h"
#include "phrase_generator.h"

class look_busy: public application
{
public:
  /**
   * Class constructor. Initializes variables.
   */
  look_busy();
  
  /**
   * Class destructor. Peforms cleanup and deallocates dynamic memory.
   */
  ~look_busy();
  
  /**
   * see application::run(int, char**)
   */
  int run(int argc, char** argv);
  
private:
  phrase_generator pg;
};

#endif /* defined(__LOOK_BUSY_H__) */
