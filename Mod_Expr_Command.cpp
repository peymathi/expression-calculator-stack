/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Mod_Expr_Command class

#include "Mod_Expr_Command.h"

virtual int Mod_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum % secondNum;
}
