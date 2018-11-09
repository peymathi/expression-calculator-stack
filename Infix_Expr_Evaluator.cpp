/* I pledge that I have neither given nor received any help on this assignment */

// Implemenation for the Infix_Expr_Evaluator class

#include "Infix_Expr_Evaluator.h"

// Default Constructor
Infix_Expr_Evaluator::Infix_Expr_Evaluator(void)
: infix_(),
  postfix_(new Queue<Expr_Command*>()),
  current_operands_(new Stack<int>()),
  result_()
{}

// Inititializing constructor
Infix_Expr_Evaluator::Infix_Expr_Evaluator(std::string infix)
: infix_(infix),
  postfix_(new Queue<Expr_Command*>()),
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

  this->result_ = this->current_operands_->top();
  return this->current_operaands_->pop();
}

// Move Commands
void Infix_Expr_Evaluator::move_commands(Expr_Command * currentCommand, Stack<Expr_Command*> & currentOperators)
{
  // Pop, push, and enqueue various commands to where they need to go based on the infix to postfix algorithm

  // If the token is a "+" or a "-"
  if(currentCommand->type == "ADD" || currentCommand->type == "SUB")
  {
    // Pop elements off the stack and enqueue until stack is empty or an open parenthesis is found
    while(!currentOperators->is_empty() || currentOperators->top() == nullptr)
    {
      this->postfix_->enqueue(currentOperators->pop());
    }

    // Push this command onto the stack
    currentOperators->push(currentCommand);
  }

  // If the token is "*", "/", or "%"
  else if(currentCommand->type == "MOD" || currentCommand->type == "DIVIDE" || currentCommand->type == "MULTIPY")
  {
    // Pop elements off the stack and enqueue until stack is empty, open parenthesis is found,
    // or top is of lower precedence
    while(!currentOperators->is_empty())
    {
      if(currentOperators->top() == nullptr || currentOperators->top()->type == "ADD"
          || this->current_operands->top()->type == "SUB")
      {
        break;
      }

      this->postfix_->enqueue(currentOperators->pop());
    }

    currentOperators->push(currentCommand);
  }
}

// Infix To Postfix Conversion
void Infix_Expr_Evaluator::infix_to_postfix(void)
{
  // Create an Expr_Command_Factory
  Expr_Command_Factory factory = Stack_Expr_Command_Factory();

  // Stream for parsing the infix string
  std::istringstream stream(this->infix_);

  // Tells the stream to ignore whitespace
  stream.ignore(strlen(this->infix_), " ");

  // String to hold the current parsed token
  std::string token;

  // Temporary pointer to hold newly created commands
  Expr_Command * currentCommand = nullptr;

  // Stack used to hold operators for conversion
  Stack<Expr_Command*> * currentOperators = new Stack<Expr_Command*>();

  // Iterate through the entire string to parse it
  while(!stream.eof())
  {
    // Get the current token
    stream >> token;

    // Test the token for each type to create a specific command and decide what to do with that command
    // If the token is a number, create a number command and enqueue it on the Queue of commands
    if(isdigit(token))
    {
      currentCommand = factory->create_number_command((int) token);
      this->postfix_->enqueue(currentCommand);
    }

    // Create addition command and push to stack of commands
    else if(token == "+")
    {
      currentCommand = factory->create_add_command();
      this->move_commands(currentCommand);
    }

    // Create subtraction command and push to stack of commands
    else if(token == "-")
    {
      currentCommand = factory->create_sub_command();
      this->move_commands(currentCommand);
    }

    // Create division command and push to stack of commands
    else if(token == "/")
    {
      currentCommand = factory->create_divide_command();
      this->move_commands(currentCommand);
    }

    // Create multiplication command and push to stack of commands
    else if(token == "*")
    {
      currentCommand = factory->create_multiply_command();
      this->move_commands(currentCommand);
    }

    // Create modulus command and push to stack of commands
    else if(token == "%")
    {
      currentCommand = factory->create_mod_command();
      this->move_commands(currentCommand);
    }

    // Create Open Parenthesis Command Object and push to stack of commands
    else if(token == "(")
    {
      // Operator has no execution and is only needed in conversion. Therefore it is represented as nullptr
      currentCommand = nullptr;

      // No need to check for precedence because this operator is of highest precedence
      currentOperators->push(currentCommand);
    }

    // Pop operator commands off the stack until "(" is found
    else if(token == ")")
    {
      // Pops elements off the stack and enqueues them to postfix_ until open parenthesis is found
      while(!currentOperators->top() == nullptr)
      {
         this->postfix_->enqueue(currentOperators->pop());
      }
    }

    // Invalid Token. Throw invalid token exception
    else
    {

    }
  }

  delete currentOperators;
}

// Execute Commands
void Infix_Expr_Evaluator::execute_commands(void)
{
  // Current Command object
  Expr_Command * currentCommand = nullptr;

  // Iterate through all command objects in the Queue
  while(!this->postfix_->is_empty())
  {
    // Set the temporary command pointer to point to the next command
    currentCommand = this->postfix->dequeue();

    // Execute the command
    currentCommand->execute();

    // Delete the command object
    delete currentCommand;
  }
}
