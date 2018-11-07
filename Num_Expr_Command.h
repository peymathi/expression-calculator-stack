/* I pledge that I have neither given nor received any help on this assignment */

/* This is a subclass of the Expr_Command class. This sum class implements the execute() method to
  add a number a number to the reference to the stack of current operands of the post fix expression

  This class contains the stack reference and the integer number as members */

#ifndef _NUM_EXPR_COMMAND_
#define _NUM_EXPR_COMMAND_

#include "Expr_Command.h"

// COMMENT: Do not write implementation code in the header file. Create
// a separate .cpp file for the implementation.

// REPLY: Seperated the implementation from the header file.

class Num_Expr_Command : public Expr_Command
{
public:
  // Initializing constructor with the next operand to be pushed to the stack
  Num_Expr_Command(int next_int)
  : next_int_(next_int)
  {}

  // Pushes the next integer in the expression to the stack of current operands. Declared virtual for further
  // extension if necessary
  virtual void execute(Stack <int> & currentOperands);

  // Setter method for nextInt
  void set_next_int(int next_int);

private:
  // Next Integer from postfix expression
  int next_int_;
};

#endif
