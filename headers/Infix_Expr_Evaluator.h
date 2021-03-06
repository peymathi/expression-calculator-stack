/* I pledge that I have neither given nor received any help on this assignment */

/* This class is a wrapper class for all the components of the Infix Expression Evaluator. This class
 allows the client to easily use all of the components of the expression evaluator by using only this class.

 This class converts the given infix string into a queue of Expr_Commands using a Stack_Expr_Command_Factory,
 then it executes all the commands in the queue and returns the result. This class also stores that result as
 in state to save for later use.
*/


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
#include "Queue.h"
#include <string.h>
#include <sstream>
#include <stdlib.h>

class Infix_Expr_Evaluator
{
public:

  // Exception to be thrown for an invalid token
  class invalid_token : public std::exception
  {
  public:
    // Default Constructor
    invalid_token(void)
    : std::exception() {}

  };

  // Exception to be thrown for a logic error in the expression (example: an open parenthesis without a close parenthesis)
  class logic_exception : public std::exception
  {
  public:
    // Default Constructor
    logic_exception(void)
    : std::exception() {}

  };

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

  // Queue of commands in postfix order to be executed
  Queue<Expr_Command*> * postfix_;

  // Stack of current operands
  Stack<int> * current_operands_;

  // Result of evalutating the commands
  int result_;

  /* All methods below are necessary operations for the infix expression evaluation. They cannot not
    be called by the user because the user should only call the evaluateExpression() method. */

  // Converts the infix string to a Queue of commands in postfix order
  void infix_to_postfix(void);

  // Helper method to infix_to_postfix method. Moves commands around to keep the algorithm going
  void move_commands(Expr_Command * currentCommand, Stack<Expr_Command*> & currentOperators);

  // Helper method to infix_to_postfix method. Tests a string to see if it is an integer
  bool is_int(std::string test);

  // Executes all commands in the postfix_ member Array
  void execute_commands(void);

};

// Include inline implemenation
#include "Infix_Expr_Evaluator.inl"

#endif
