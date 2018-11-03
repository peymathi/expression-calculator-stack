/* I pledge that I have neither given nor received any help on this assignment */

// Implementation of Stack_Expr_Command_Factory class

#include "Stack_Expr_Command_Factory.h"

// create_number_command
inline
Num_Expr_Command * Stack_Expr_Command_Factory::create_number_command(int num)
{
  return new Num_Expr_Command(num);
}

// create_add_command
inline
Add_Expr_Command * Stack_Expr_Command_Factory::create_add_command(void)
{
  return new Add_Expr_Command();
}

// create_sub_command
inline
Subtract_Expr_Command * Stack_Expr_Command_Factory::create_sub_command(void)
{
  return new Subtract_Expr_Command();
}

// create_multiply_command
inline
Multiply_Expr_Command * Stack_Expr_Command_Factory::create_multiply_command(void)
{
  return new Multiply_Expr_Command();
}

// create_divide_command
inline
Divide_Expr_Command * Stack_Expr_Command_Factory::create_divide_command(void)
{
  return new Divide_Expr_Command();
}

// create_mod_command
inline
Mod_Expr_Command * Stack_Expr_Command_Factory::create_mod_command(void)
{
  return new Mod_Expr_Command();
}
