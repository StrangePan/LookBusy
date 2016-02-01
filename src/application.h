#ifndef __APPLICATION_H__
#define __APPLICATION_H__

/**
 * Represents a generic application object. Contains methods for running and
 * controlling the execution of an application.
 */
class application
{
public:
  /**
   * Class destructor.
   */
  virtual ~application() {};
  
  /**
   * Executes the program. Accepts the commandline arguments supplied to `main`.
   * 
   * argc - The number of space-separated commandline arguments. Can be used as
   *        an upperbound for the `argv` array.
   * argv - Array of c-style strings containing the commandline arguments.
   * 
   * returns Integer representing the status of the program after completion.
   */
  virtual int run(int argc, char** argv) = 0;
};

#endif /* defined(__APPLICATION_H__) */
