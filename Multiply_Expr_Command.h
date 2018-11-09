/* I pledge that I have neither given nor recieved any help on this assignment */

// This class is a subclass of Bin_Expr_Command. It implements the evaluate() method defined virtually in
// Bin_Expr_Command in order to carry out the specific operation and continue the algorithm defined in Bin_Expr_Command

#ifndef _MULTIPLY_EXPR_COMMAND_
#define _MULTIPLY_EXPR_COMMAND_

#include "Bin_Expr_Command.h"

// COMMENT: Do not write implementation code in the header file. Create
// a separate .cpp file for the implementation.

// REPLY: Seperated the implementation from the header file.

class Multiply_Expr_Command : public Bin_Expr_Command
{
public:

  // Constant for identifying which type this object is
  const std::string TYPE = "MULTIPLY";

  // Initializing constructor
  Multiply_Expr_Command(Stack<int> & current_operands);

  // Implements the evaluate method of Bin_Expr_Command to multiply the two numbers popped off the stack and
  // then return them in order to continue the algorithm. Method is still declared virtual for further extension
  // if necessary in the future.
  virtual int evaluate(int firstNum, int secondNum) const;
};

#endif
