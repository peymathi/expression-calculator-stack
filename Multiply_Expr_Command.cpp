/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Multiply_Expr_Command class

#include "Multiply_Expr_Command.h"

// Constructor initializes the base class member variables
Multiply_Expr_Command::Multiply_Expr_Command(Stack<int> & current_operands)
: Bin_Expr_Command("MULTIPLY", current_operands)
{}

int Multiply_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum * secondNum;
}
