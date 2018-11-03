/* I pledge that I have neither given nor received any help on this assignment */

// This class creates Command objects and puts them into an Array by parsing
// an infix string expression and creating specific Command objects based on each token

#ifndef _EXPR_COMMAND_FACTORY_
#define _EXPR_COMMAND_FACTORY_

#include "Num_Expr_Command.h"
#include "Add_Expr_Command.h"
#include "Sub_Expr_Command.h"
#include "Multiply_Expr_Command.h"
#include "Divide_Expr_Command.h"
#include "Mod_Expr_Command.h"

class Expr_Command_Factory
{
public:
  // Destructor
  virtual ~Expr_Command_Factory() = 0;

  // Method that creates a new Num_Expr_Command
  virtual Num_Expr_Command * create_number_command (int num) = 0;

  // Method that creates a new Add_Expr_Command
  virtual Add_Expr_Command * create_add_command (void) = 0;

  // Method that creates a new Sub_Expr_Command
  virtual Sub_Expr_Command * create_sub_command (void) = 0;

  // Method that creates a new Multiply_Expr_Command
  virtual Multiply_Expr_Command * create_multiply_command (void) = 0;

  // Method that creates a new Divide_Expr_Command
  virtual Divide_Expr_Command * create_divide_command (void) = 0;

  // Method that creates a new Mod_Expr_Command
  virtual Mod_Expr_Command * create_mod_command (void) = 0;

private:
  // Blocks the use of the copy constructor
  Expr_Command_Factory(const Expr_Command_Factory & );

  // Blocks the use of the assignment operator with this object
  const Expr_Command_Factory & operator = (const Expr_Command_Factory &);
};

#endif
