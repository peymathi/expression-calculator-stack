/* I pledge that I have neither given nor received any help on this assignment */

/* This is a subclass of the Expr_Command class. This sum class implements the execute() method to
  add a number a number to the reference to the stack of current operands of the post fix expression

  This class contains the stack reference and the integer number as members */

#ifndef _NUM_EXPR_COMMAND_
#define _NUM_EXPR_COMMAND_

#include "Expr_Command.h"

// COMMENT: Do not write implementation code in the header file. Create
// a separate .cpp file for the implementation.

class Num_Expr_Command : public Expr_Command
{
public:
  // Default Constructor
  Num_Expr_Command()
  : next_int_()
  {}

  // Initializing constructor with the next operand to be pushed to the stack
  Num_Expr_Command(int next_int)
  : next_int_(next_int)
  {}

  // Pushes the next integer in the expression to the stack of current operands. Declared virtual for further
  // extension if necessary
  virtual void execute(Stack <int> & currentOperands)
  {
    currentOperands.push(next_int_);
  }

  // Setter method for nextInt
  void set_next_int(int next_int)
  {
    this->next_int_ = next_int;
  }

private:
  // Next Integer from postfix expression
  int next_int_;
};

#endif
