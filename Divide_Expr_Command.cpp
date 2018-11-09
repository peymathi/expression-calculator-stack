/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Divide_Expr_Command class

#include "Divide_Expr_Command.h"

Divide_Expr_Command::Divide_Expr_Command(Stack<int> & current_operands)
: Expr_Command(current_operands)
{}

virtual int Divide_Expr_Command::evalutate(int firstNum, int secondNum) const
{
  return firstNum / secondNum;
}
