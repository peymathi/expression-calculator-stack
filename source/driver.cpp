/* I pledge that I have neither given nor received any help on this assignment */

#include "Infix_Expr_Evaluator.h"

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

// REPLY: Created a wrapper class named Infix_Expr_Evaluator to allow the client ease of use

// COMMENT: Improve the design of your commands to reduce the design
// complexity of this method. Right now, there are too many if-else
// statements, and a lot of duplicate code.

// REPLY: Improved the design. Removed redundant code. See Infix_Expr_Evaluator class for this change

// COMMENT: I do not see where you are taking into account the precedence
// of the operator during the conversion process.

// REPLY: Took operator precedence into account within the move_commands() method in Infix_Expr_Evaluator class

int main()
{
	// String to hold userInput
	std::string userInput;

	// Wrapper object to evaluate expression
	Infix_Expr_Evaluator * evaluator = new Infix_Expr_Evaluator();

	while(true)
	{
		// Tell the user how the program works and get their input
		std::cout << "Enter an Infix Expression or enter QUIT to quit: ";
		std::getline(std::cin, userInput);

		// Test the input to see if the user wants to quit
		if(userInput == "QUIT")
		{
			break;
		}

		// Set the infix string of the evaluator object to the string inputted by the user
		evaluator->setInfix(userInput);

		// Try-Catch block to catch all exceptions that could arise from evaluating the expression
		try
		{
			// Call the evaluateExpression method and print the result
			std::cout << evaluator->evaluateExpression() << std::endl;
		}

		// Catch the invalid_token exception. Explain to the user the error with their expression and continue
		catch(Infix_Expr_Evaluator::invalid_token ex)
		{
			std::cout << "Invalid Token in the entered expression. Please try again." << std::endl;
		}

		// Catch the logic_exception exception. Explain to the user the error with their expression and continue
		catch(Infix_Expr_Evaluator::logic_exception ex)
		{
			std::cout << "Logic error in the entered expression. Please try again." << std::endl;
		}

		// Catch divide by zero exception. Explain to the user the error with their expression and continue
		catch(Divide_Expr_Command::divide_by_zero ex)
		{
			std::cout << "Logic Error: Expression attempts to divide by zero. Please try again." << std::endl;
		}

		// Catch mod by zero exception. Explain to the user the error with their expression and continue
		catch(Mod_Expr_Command::mod_by_zero ex)
		{
			std::cout << "Logic Error: Expression attempt to take a modulus by zero. Please try again." << std::endl;
		}

		// Catch any other exceptions
		catch(...)
		{
			std::cout << "Unknown error. Please try again" << std::endl;
		}
	}

	delete evaluator;

	return 0;

}
