/* I pledge that I have neither given nor received any help on this assignment */

// Implmementation for Subtract_Expr_Command class

#include "Subtract_Expr_Command.h"

Subtract_Expr_Command::Subtract_Expr_Command(Stack<int> & current_operands)
: Expr_Command(current_operands)
{}

virtual int Subtract_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum - secondNum;
}
