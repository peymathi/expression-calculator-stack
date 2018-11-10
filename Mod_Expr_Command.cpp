/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Mod_Expr_Command class

#include "Mod_Expr_Command.h"

// Constructor initializes the base class member variables
Mod_Expr_Command::Mod_Expr_Command(Stack<int> & current_operands)
: Bin_Expr_Command("MOD", current_operands)
{}

int Mod_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  // Throw mod by zero exception if the second number is zero
  if(secondNum == 0)
  {
    throw mod_by_zero();
  }

  return firstNum % secondNum;
}
