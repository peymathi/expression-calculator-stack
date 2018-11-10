/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Divide_Expr_Command class

#include "Divide_Expr_Command.h"

// Constructor initializes the base class member variables
Divide_Expr_Command::Divide_Expr_Command(Stack<int> & current_operands)
: Bin_Expr_Command("DIVIDE", current_operands)
{}

int Divide_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  // Throw divide by zero exception if the second number is zero
  if(secondNum == 0)
  {
    throw divide_by_zero();
  }

  return firstNum / secondNum;
}
