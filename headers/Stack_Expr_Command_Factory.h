/* I pledge that I have neither given nor received any help on this assignment */

// This class is a subclass of Expr_Command_Factory. It implements the methods that create various commands
// and it pushes these created commands onto a Stack object. A reference to the current Stack object
// is stored internally as a member.

#ifndef _STACK_EXPR_COMMAND_FACTORY_
#define _STACK_EXPR_COMMAND_FACTORY_

#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory : public Expr_Command_Factory
{
public:
  // Initializing constructor. Takes in one parameter which is a reference to the current Stack
  Stack_Expr_Command_Factory(Stack<int> & current_operands);

  // Destructor
  ~Stack_Expr_Command_Factory();

  // Creates a new number command
  virtual Num_Expr_Command * create_number_command (int num);

  // Creates a new add command
  virtual Add_Expr_Command * create_add_command (void);

  // Creates a new subtract command
  virtual Subtract_Expr_Command * create_sub_command (void);

  // Creates a new multiplication command
  virtual Multiply_Expr_Command * create_multiply_command (void);

  // Creates a new division command
  virtual Divide_Expr_Command * create_divide_command (void);

  // Creates a new modulus command
  virtual Mod_Expr_Command * create_mod_command (void);

private:
  // Reference to the stack of current operands
  Stack<int> & current_operands_;

};

#include "Stack_Expr_Command_Factory.inl"

#endif
