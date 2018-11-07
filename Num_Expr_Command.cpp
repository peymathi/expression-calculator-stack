/* I pledge that I have neither given nor received any help on this assignment */

// Implementation of the Num_Expr_Command class

#include "Num_Expr_Command.h"

Num_Expr_Command::Num_Expr_Command(int next_int)
: next_int_(next_int)
{}

virtual void Num_Expr_Command::execute(Stack<int> currentOperands)
{
  currentOperands.push(this->next_int_);
}

void Num_Expr_Command::set_next_int(int nextInt)
{
  this->next_int_ = nextInt;
}
