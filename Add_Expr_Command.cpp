/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for Add_Expr_Command class

#include "Add_Expr_Command.h"

// Constructor initializes the base class member variables
Add_Expr_Command::Add_Expr_Command(Stack<int> & current_operands)
: Bin_Expr_Command("ADD", current_operands)
{}

// Destructor
Add_Expr_Command::~Add_Expr_Command(void)
{}

int Add_Expr_Command::evaluate(int firstNum, int secondNum) const
{
  return firstNum + secondNum;
}
