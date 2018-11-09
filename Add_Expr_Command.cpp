/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for Add_Expr_Command class

#include "Add_Expr_Command.h"

Add_Expr_Command::Add_Expr_Command(Stack<int> & current_operands)
: Expr_Command(current_operands)
{}

virtual int Add_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum + secondNum;
}
