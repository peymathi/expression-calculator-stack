/* I pledge that I have neither given nor received any help on this assignment */

// Implementation of the constructor and Destructor for the Expr_Command class

#include "Expr_Command.h"

// Constructor
Expr_Command::Expr_Command(const std::string type, Stack<int> & current_operands)
: TYPE(type),
  current_operands_(current_operands)
{}

// Destructor
Expr_Command::~Expr_Command(void)
{}
