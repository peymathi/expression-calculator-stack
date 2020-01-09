/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for the Unary_Expr_Command class

#include "Unary_Expr_Command.h"

// Constructor
Unary_Expr_Command::Unary_Expr_Command(const std::string type, Stack<int> & current_operands)
: Expr_Command(type, current_operands)
{}

// Destructor
Unary_Expr_Command::~Unary_Expr_Command(void)
{}

void Unary_Expr_Command::execute(void)
{
  int operand = this->current_operands_.pop();

  int result = this->evaluate(operand);
  current_operands_.push(result);
}
