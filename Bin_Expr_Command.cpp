/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Bin_Expr_Command class

#include "Bin_Expr_Command.h"

virtual void Bin_Expr_Command::execute (Stack <int> & currentOperands)
{
  int secondNum = currentOperands.pop();
  int firstNum = currentOperands.pop();

  int result = this->evaluate(firstNum, secondNum);
  currentOperands.push(result);
}
