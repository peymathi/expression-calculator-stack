/* I pledge that I have neither given nor received any help on this assignment */

/* This class is a subclass of Bin_Expr_Command. This class implements the evaluate() method defined virtually
 in Bin_Expr_Command in order to subtract the two numbers popped from the stack. */

#ifndef _SUBTRACT_EXPR_COMMAND_
#define _SUBTRACT_EXPR_COMMAND_

#include "Bin_Expr_Command.h"

class Subtract_Expr_Command : public Bin_Expr_Command
{
public:

  // Implements the evaluate method of Bin_Expr_Command to subtract the two numbers popped off the stack and
  // then return them in order to continue the algorithm. Method is still declared virtual for further extension
  // if necessary in the future.
  virtual int evaluate(int firstNum, int secondNum) const
  {
    return firstNum - secondNum;
  }
};

#endif
