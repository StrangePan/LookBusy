#ifndef __LOOK_BUSY_H__
#define __LOOK_BUSY_H__

#include "application.h"
#include "phrase_generator.h"

/**
 * Main application class. Contains core functionality for program.
 * 
 * Extends the `application` class.
 */
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
  
  /**
   * Performs a short-running task that displays a randomly generated phrase
   * for a short time.
   */
  void do_short_task();
  
  /**
   * Performs a short-running task that displays a randomly generated phrase
   * followed up by a confirmation message.
   */
  void do_short_task_with_confirm();
  
  /**
   * Performs a random long-running task. Randomly invokes one of the other
   * long-running tasks.
   * 
   * - `do_long_task_with_spinner()`
   * - `do_long_task_with_progress_bar()`
   * - `do_long_task_with_progress_percent()`
   * - `do_long_task_with_dots()`
   */
  void do_long_task();
  
  /**
   * Performs a long-running task that includes a spinning animation that runs
   * for a randomly-chosen amount of time.
   * 
   * This method may randomly be invoked when calling `do_long_task()`.
   */
  void do_long_task_with_spinner();
  
  /**
   * Performs a long-running task that includes a progress bar animation that
   * runs for a randomly-chosen amount of time.
   * 
   * This method may randomly be invoked when calling `do_long_task()`.
   */
  void do_long_task_with_progress_bar();
  
  /**
   * Performs a long-running task that includes a progress percentage indicator
   * that runs for a randomly-chosen amount of time.
   * 
   * This method may randomly be invoked when calling `do_long_task()`.
   */
  void do_long_task_with_progress_percent();
  
  /**
   * Performs a long-running task that includes incrementally-appearing dots to
   * indicate progress that runs for a randomly-chosen amount of time and may
   * span multiple lines.
   * 
   * This method may randomly be invoked when calling `do_long_task()`.
   */
  void do_long_task_with_dots();
  
  
  
private:
  
  /**
   * The applications `phrase_generator` object for generating random task
   * messages.
   */
  phrase_generator pg;
};

#endif /* defined(__LOOK_BUSY_H__) */
