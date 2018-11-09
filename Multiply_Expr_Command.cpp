/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Multiply_Expr_Command class

#include "Multiply_Expr_Command.h"

Multiply_Expr_Command::Multiply_Expr_Command(Stack<int> & current_operands)
: Expr_Command(current_operands)
{}

virtual int Multiply_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum * secondNum;
}
