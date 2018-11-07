#include "Add_Expr_Command.h"
#include "Multiply_Expr_Command.h"
#include "Divide_Expr_Command.h"
#include "Subtract_Expr_Command.h"
#include "Num_Expr_Command.h"
#include "Mod_Expr_Command.h"
#include "Array_Iterator.h"
#include "Stack_Expr_Command_Factory.h"
#include "Unary_Expr_Command.h"

// This is the client for the expression evaluator. I was considering making a wrapper class, but I ran out of time

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.


void infix_to_postfix(const std::string & infixString, Expr_Command_Factory & factory, Array<Expr_Command*> & postfix)
{
	// Stream for parsing the infix string
	std::istringstream input(infixString);

	// Token which will be used to make a command
	std::string token;

	// Current indice of the postfix expression
	size_t indice = 0;

	// Temporary container for a command object to hold a command before it's decided where to put it
	Expr_Command * tempCommand;

	// Stack used for infix to postfix alogorithm. Holds operator commands
	Stack<std::string> operatorTokens;

	// Runs until the end of stream
	while(!input.eof())
	{
    
    // COMMENT: Improve the design of your commands to reduce the design
    // complexity of this method. Right now, there are too many if-else
    // statements, and a lot of duplicate code.

    // COMMENT: I do not see where you are taking into account the precedence
    // of the operator during the conversion process.
    
		// Assign the current input to the token string
		input >> token;

		// Create command objects based on what the token is
		// Addition, Subtraction, Multiply, Division, Modulus Operators
		if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
		{
			operatorTokens.push(token);
		}

		// Open
		else if(token == "(")
		{
			operatorTokens.push(token);
		}

		// Close. Pop's all tokens off the stack and adds them to postfix expression as operators until
		// open is found.
		else if(token == ")")
		{
			while(true)
			{
				token = operatorTokens.pop();
				if(token == "(")
				{
					operatorTokens.pop();
					break;
				}

				else if(token == "+")
				{
					tempCommand = factory.create_add_command();
					postfix[indice] = tempCommand;
					indice++;
				}

				else if(token == "-")
				{
					tempComand = factory.create_sub_command();
					postfix[indice] = tempCommand;
					indice++;
				}

				else if(token == "*")
				{
					tempCommand = factory.create_multiply_command();
					postfix[indice] = tempCommand;
					indice++;
				}

				else if(token == "/")
				{
					tempCommand = factory.create_divide_command();
					postfix[indice] = tempCommand;
					indice++;
				}

				else if(token == "%")
				{
					tempCommand = factory.create_mod_command();
					postfix[indice] = tempCommand;
					indice++;
				}
			}
		}

		// Space
		else if(token == " ")
		{}

		// Number
		else
		{
			postfix[indice] == factory.create_num_command(int(token));
			indice++;
		}

	}

	// Pop all elements off stack and make them command objects on the array of commands
	while(!operatorTokens.is_empty())
	{
		token == operatorTokens.pop();
		if(token == "+")
		{
			postfix[indice] = factory.create_add_command();
			indice++;
		}

		else if(token == "-")
		{
			postfix[indice] = factory.create_sub_command();
			indice++;
		}

		else if(token == "*")
		{
			postfix[indice] = factory.create_multiply_command();
			indice++
		}

		else if(token == "/")
		{
			postfix[indice] = factory.create_divide_command();
			indice++;
		}

		else if(token == "%")
		{
			postfix[indice] = factory.create_mod_command();
			indice++;
		}
	}


}

int main()
{
	std::string userInput;

	while(userInput != "QUIT")
	std::cout << "Enter your expression or type QUIT: ";
	std::cin >> userInput;
	std::cout << std::endl;
	size_t arraySize = 0;

	std::istringstream input(userInput);
	std::string token;

	while(!input.eof())
	{
		input >> token;
		if(token == "+")
		{
			arraySize++;
		}

		else if(token == "-")
		{
			arraySize++;
		}

		else if(token == "*" || token == "/" || token == "%")
		{
			arraySize++;
		}

		else if(token == "(" || token == ")" || token == " ")
		{}

		else
		{
			arraySize++;
		}
	}

	Array<Expr_Command*> * postfix = new Array<Expr_Command*>(arraySize);
	Expr_Command_Factory factory = Expr_Command_Factory();
	std::string infix;

	infix_to_postfix(infix, factory, *postfix);

	Stack<int> numbers = Stack<int>();

	// Evaluate Postfix expression
	for(Array_Iterator iter(*postfix); !iter.is_done(); iter.advance())
	{
		(*iter)->execute(numbers);
	}

	std::cout << "Answer: " << numbers.pop() << std::endl;
}
