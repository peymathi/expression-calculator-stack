/* I pledge that I have neither given nor received any help on this assignment */

/* Sub class of the Expr_Command interface. Provides template algorithm for all Expression Commands
  that use two tokens other than the operator. Implements the execute command inherited from the
  Expr_Command interface and declares a new pure virtual method evaluate for sub classes to implement */

#ifndef _BIN_EXPR_COMMAND_
#define _BIN_EXPR_COMMAND_

#include "Expr_Command.h"

// COMMENT: Do not write implementation code in the header file. Create
// a separate .cpp file for the implementation.

// REPLY: Seperated the implementation from the header file.

class Bin_Expr_Command : public Expr_Command
{
public:
  // Each binary operation will follow the same general algorithm to execute the command. This method provides
  // the skeleton of the alogorithm with each subclass implementing the evaluate() method to complete the algorithm.
  virtual void execute ();

  // To be implemented in subclasses with the specific evaluation of the subclasses expression operation
  virtual int evaluate (int firstNum, int secondNum) const = 0;
};

#endif
