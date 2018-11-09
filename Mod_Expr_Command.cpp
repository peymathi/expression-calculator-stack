/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Mod_Expr_Command class

#include "Mod_Expr_Command.h"

Mod_Expr_Command::Mod_Expr_Command(Stack<int> & current_operands)
: Expr_Command(current_operands)
{}

virtual int Mod_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum % secondNum;
}
