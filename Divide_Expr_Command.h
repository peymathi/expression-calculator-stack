/* I pledge that I have neither given nor recieved any help on this assignment */

// This class is a subclass of Bin_Expr_Command. It implements the evaluate() method defined virtually in
// Bin_Expr_Command in order to carry out the specific operation and continue the algorithm defined in Bin_Expr_Command

#ifndef _DIVIDE_EXPR_COMMAND_
#define _DIVIDE_EXPR_COMMAND_

#include "Bin_Expr_Command.h"

// COMMENT: Do not write implementation code in the header file. Create
// a separate .cpp file for the implementation.

// REPLY: Seperated the implementation from the header file.

class Divide_Expr_Command : public Bin_Expr_Command
{
public:

  // Implements the evaluate method of Bin_Expr_Command to divide the two numbers popped off the stack and
  // then return them in order to continue the algorithm. Method is still declared virtual for further extension
  // if necessary in the future.
  virtual int evaluate(int firstNum, int secondNum) const;
};

#endif
