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

// Inititializing constructor. Initializes the Queue to be the size of the array
Infix_Expr_Evaluator::Infix_Expr_Evaluator(std::string infix)
: infix_(infix),
  postfix_(new Queue<Expr_Command*>(infix.length())),
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
  return this->current_operands_->pop();
}

// Move Commands
void Infix_Expr_Evaluator::move_commands(Expr_Command * currentCommand, Stack<Expr_Command*> & currentOperators)
{
  // Pop, push, and enqueue various commands to where they need to go based on the infix to postfix algorithm

  // If the token is a "+" or a "-"
  if(currentCommand->TYPE == "ADD" || currentCommand->TYPE == "SUBTRACT")
  {
    // Pop elements off the stack and enqueue until stack is empty or an open parenthesis is found
    while(!currentOperators.is_empty() && !(currentOperators.top() == nullptr))
    {
      this->postfix_->enqueue(currentOperators.pop());
    }

    // Push this command onto the stack
    currentOperators.push(currentCommand);
  }

  // If the token is "*", "/", or "%"
  else if(currentCommand->TYPE == "MOD" || currentCommand->TYPE == "DIVIDE" || currentCommand->TYPE == "MULTIPLY")
  {
    // Pop elements off the stack and enqueue until stack is empty, open parenthesis is found,
    // or top is of lower precedence
    while(!currentOperators.is_empty())
    {
      if(currentOperators.top() == nullptr || currentOperators.top()->TYPE == "ADD"
          || currentOperators.top()->TYPE == "SUBTRACT")
      {
        break;
      }

      this->postfix_->enqueue(currentOperators.pop());
    }

    currentOperators.push(currentCommand);
  }
}

// Integer Test
bool Infix_Expr_Evaluator::is_int(std::string test)
{
  // Converts the string to a c style string. Test's each char in the array if it is a digit to determine
  // if the string is an integer.
  const char * cstring = test.c_str();

  // If the length is greater than one, we can test for negative numbers
  if(test.length() > 1)
  {
    for(size_t i = 0; i < test.length(); i++)
    {
      if(!isdigit(cstring[i]) && cstring[i] != '-')
      {
        return false;
      }

      return true;
    }
  }

  // If the length is not greater than one, then we do not need to test for negative numbers
  for(size_t i = 0; i < test.length(); i++)
  {
    if(!isdigit(cstring[i]))
    {
      return false;
    }
  }

  return true;
}

// Infix To Postfix Conversion
void Infix_Expr_Evaluator::infix_to_postfix(void)
{
  // Create an Expr_Command_Factory
  Expr_Command_Factory * factory = new Stack_Expr_Command_Factory(*this->current_operands_);

  // String to hold the current parsed token
  std::string token;

  // String stream to parse the data
  std::istringstream stream(this->infix_);

  // Temporary pointer to hold newly created commands
  Expr_Command * currentCommand = nullptr;

  // Stack used to hold operators for conversion
  Stack<Expr_Command*> * currentOperators = new Stack<Expr_Command*>();

  // Iterate through the entire string to parse it
  while(!stream.eof())
  {
    stream >> token;

    // Test the token for each type to create a specific command and decide what to do with that command
    // If the token is a number, create a number command and enqueue it on the Queue of commands
    if(this->is_int(token))
    {
      // Converts the string token to an integer to make the number command
      currentCommand = factory->create_number_command(std::stoi(token));
      this->postfix_->enqueue(currentCommand);
    }

    // Create addition command and push to stack of commands
    else if(token == "+")
    {
      currentCommand = factory->create_add_command();
      this->move_commands(currentCommand, *currentOperators);
    }

    // Create subtraction command and push to stack of commands
    else if(token == "-")
    {
      currentCommand = factory->create_sub_command();
      this->move_commands(currentCommand, *currentOperators);
    }

    // Create division command and push to stack of commands
    else if(token == "/")
    {
      currentCommand = factory->create_divide_command();
      this->move_commands(currentCommand, *currentOperators);
    }

    // Create multiplication command and push to stack of commands
    else if(token == "*")
    {
      currentCommand = factory->create_multiply_command();
      this->move_commands(currentCommand, *currentOperators);
    }

    // Create modulus command and push to stack of commands
    else if(token == "%")
    {
      currentCommand = factory->create_mod_command();
      this->move_commands(currentCommand, *currentOperators);
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
      while(!(currentOperators->top() == nullptr))
      {
        this->postfix_->enqueue(currentOperators->pop());
      }

      // Pops off the open parenthesis
      currentOperators->pop();
    }

    // Invalid Token. Throw invalid token exception
    else
    {
      throw invalid_token();
    }
  }

  // End of infix expression. Pop all operators off the stack an enquee to postfix
  while(!currentOperators->is_empty())
  {
    this->postfix_->enqueue(currentOperators->pop());
  }

  delete currentOperators;
  delete factory;
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
    currentCommand = this->postfix_->dequeue();

    // Execute the command
    currentCommand->execute();

    // Delete the command object
    delete currentCommand;
  }
}
