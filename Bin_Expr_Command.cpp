/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Bin_Expr_Command class

#include "Bin_Expr_Command.h"

virtual void Bin_Expr_Command::execute (void)
{
  int secondNum = this->current_operands_.pop();
  int firstNum = this->current_operands_.pop();

  int result = this->evaluate(firstNum, secondNum);
  this->current_operands_.push(result);
}
