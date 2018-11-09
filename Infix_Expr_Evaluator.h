/* I pledge that I have neither given nor received any help on this assignment */

// This class is a wrapper class for all the components of the Infix Expression Evaluator. This class
// allows the client to easily use all of the components of the expression evaluator by using only this class.
// Goal for this class is to allow the client to create this object, and then call one method to get the result

#ifndef _INFIX_EXPR_EVALUATOR_
#define _INFIX_EXPR_EVALUATOR_

#include "Add_Expr_Command.h"
#include "Multiply_Expr_Command.h"
#include "Divide_Expr_Command.h"
#include "Subtract_Expr_Command.h"
#include "Num_Expr_Command.h"
#include "Mod_Expr_Command.h"
#include "Array_Iterator.h"
#include "Stack_Expr_Command_Factory.h"
#include "Unary_Expr_Command.h"

class Infix_Expr_Evaluator
{
public:
  // Default constructor
  Infix_Expr_Evaluator(void);

  // Inititializing constructor
  Infix_Expr_Evaluator(std::string infix);

  // Destructor
  ~Infix_Expr_Evaluator(void);

  // Setter method for infix string member. Allows reuse of this object
  void setInfix(std::string infix);

  // Getter method for the result integer member. Allows the client to get the result of the evaluation a second time
  int getResult(void);

  // Method to be called by the user to evaluate the current infix expression inputted to this object.
  // This method calls all methods necessary to complete the evaluation. Returns the result.
  int evaluateExpression(void);

private:
  // Infix string
  std::string infix_;

  // Array of commands in postfix order to be executed
  Array<Command*> * postfix_;

  // Stack of current operands
  Stack<int> * current_operands_;

  // Result of evalutating the commands
  int result_;

  /* All methods below are necessary operations for the infix expression evaluation. They cannot not
    be called by the user because the user should only call the evaluateExpression() method. */

  // Converts the infix string to an Array of commands in postfix order
  void infix_to_postfix(void);

  // Executes all commands in the postfix_ member Array
  void execute_commands(void);

  // Cleans up the allocated commands stored in the postfix Array
  void delete_commands(void);

};

// Include inline implemenation
#include "Infix_Expr_Evaluator.inl"

#endif
