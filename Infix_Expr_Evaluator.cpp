/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for the Infix_Expr_Evaluator class

#include "Infix_Expr_Evaluator.h"

// Default Constructor
Infix_Expr_Evaluator::Infix_Expr_Evaluator(void)
: infix_(),
  postfix_(new Array<Command*>()),
  current_operands_(new Stack<int>()),
  result_()
{}

// Inititializing constructor
Infix_Expr_Evaluator::Infix_Expr_Evaluator(std::string infix)
: infix_(infix),
  postfix_(new Array<Command*>()),
  current_operands_(new Stack<int>()),
  result_()
{}

// Destructor
Infix_Expr_Evaluator::~Infix_Expr_Evaluator(void)
{
  delete this->postfix_;
  delete this->current_operands_;
}

// Evaluate Expression
int Infix_Expr_Evaluator::evaluateExpression(void)
{
  // Call the infix_to_postfix method
  this->infix_to_postfix();

  // Call the execute_commands method
  this->execute_commands();

  // Call the delete_commands method
  this->delete_commands();
}

// Infix To Postfix Conversion
void Infix_Expr_Evaluator::infix_to_postfix(void)
{
  // Create an Expr_Command_Factory
  Expr_Command_Factory factory = Stack_Expr_Command_Factory();
}

// Execute Commands
void Infix_Expr_Evaluator::execute_commands(void)
{

}

// Delete Commands
void Infix_Expr_Evaluator::delete_commands(void)
{
  // Delete all objects in the array
  for(Array_Iterator<Command*> iter(this->postfix_); !iter.is_done(); iter.advance())
  {
    delete *iter;
  }

  // Resize the array to zero
  this->postfix_->resize(0);
}
