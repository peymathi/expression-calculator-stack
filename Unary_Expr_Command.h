/* I pledge that I have neither given nor received any help on this assignment */

// This class is a subclass of Expr_Command. It is used for single operator commands.

#ifndef _UNARY_EXPR_COMMAND_
#define _UNARY_EXPR_COMMAND_

#include "Expr_Command.h"

class Unary_Expr_Command : public Expr_Command
{
public:

  // Provides main skeleton for an algorithm that carries out a unary operation on one operand of the stack.
  virtual void execute(Stack <int> & currentOperands)
  {
    int operand = currentOperands.pop();

    int result = this->evaluate(operand);
    currentOperands.push(result);
  }

  // Method to be implemented in subclasses of this class. Expected to carry out some operation on the number
  // and return it in order to be used in the execute() method
  virtual int evaluate(int operand) = 0;
};

#endif
