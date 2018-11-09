/* I pledge that I have neither given nor received any help on this assignment */

// Implementation of the Num_Expr_Command class

#include "Num_Expr_Command.h"

Num_Expr_Command::Num_Expr_Command(Stack<int> & current_operands, int next_int)
: Expr_Command(current_operands)
  next_int_(next_int)
{}

virtual void Num_Expr_Command::execute(Stack<int> currentOperands)
{
  currentOperands.push(this->next_int_);
}
