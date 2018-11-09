/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for the Unary_Expr_Command class

#include "Unary_Expr_Command.h"

virtual void Unary_Expr_Command::execute()
{
  int operand = this->current_operands_.pop();

  int result = this->evaluate(operand);
  current_operands_.push(result);
}
