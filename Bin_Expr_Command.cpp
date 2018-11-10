/* I pledge that I have neither given nor received any help on this assignment */

// Implementation for the Bin_Expr_Command class

#include "Bin_Expr_Command.h"

// Constructor
Bin_Expr_Command::Bin_Expr_Command(const std::string type, Stack<int> & current_operands)
: Expr_Command(type, current_operands)
{}

// Destructor
Bin_Expr_Command::~Bin_Expr_Command(void)
{}

// Execute
void Bin_Expr_Command::execute (void)
{
  int secondNum = this->current_operands_.pop();
  int firstNum = this->current_operands_.pop();

  int result = this->evaluate(firstNum, secondNum);
  this->current_operands_.push(result);
}
