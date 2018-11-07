/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for the Unary_Expr_Command class

#include "Unary_Expr_Command.h"

virtual void Unary_Expr_Command::execute(Stack <int> & currentOperands)
{
  int operand = currentOperands.pop();

  int result = this->evaluate(operand);
  currentOperands.push(result);
}
