/* I pledge that I have neither given nor received any help on this assignment */

// This class is a subclass of Expr_Command. It is used for single operator commands.

#ifndef _UNARY_EXPR_COMMAND_
#define _UNARY_EXPR_COMMAND_

#include "Expr_Command.h"

// COMMENT: Do not write implementation code in the header file. Create
// a separate .cpp file for the implementation.

// REPLY: Seperated the implementation from the header file.

class Unary_Expr_Command : public Expr_Command
{
public:

  // Provides main skeleton for an algorithm that carries out a unary operation on one operand of the stack.
  virtual void execute(Stack <int> & currentOperands);

  // Method to be implemented in subclasses of this class. Expected to carry out some operation on the number
  // and return it in order to be used in the execute() method
  virtual int evaluate(int operand) = 0;
};

#endif
