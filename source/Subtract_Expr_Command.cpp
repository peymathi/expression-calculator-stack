/* I pledge that I have neither given nor received any help on this assignment */

// Implmementation for Subtract_Expr_Command class

#include "Subtract_Expr_Command.h"

// Constructor initializes the base class member variables
Subtract_Expr_Command::Subtract_Expr_Command(Stack<int> & current_operands)
: Bin_Expr_Command("SUBTRACT", current_operands)
{}

int Subtract_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum - secondNum;
}
