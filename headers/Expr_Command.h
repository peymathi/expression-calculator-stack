/* I pledge that I have neither given nor received any help on this assignment */

/* Interface for the Expression Command Class Structure. Defines one method execute() to be implemented
  in the specific Expression Command sub classes */

#ifndef _EXPR_COMMAND_
#define _EXPR_COMMAND_

#include "Stack.h"

class Expr_Command
{
public:
  // Constructor used to initialize member variables
  Expr_Command(const std::string type, Stack<int> & current_operands);

  // Destructor
  virtual ~Expr_Command(void) = 0;

  // Execution method to be implemented in all subclasses
  virtual void execute (void) = 0;

  // Type identifier for what type of command this is
  const std::string TYPE;

protected:
  Stack<int> & current_operands_;
};

#endif
