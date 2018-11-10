#include "Infix_Expr_Evaluator.h"
#include "Stack.h"
#include "Subtract_Expr_Command.h"
#include "Add_Expr_Command.h"

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

		std::cout << userInput.length() << std::endl;

		// Test the input to see if the user wants to quit
		if(userInput == "QUIT")
		{
			break;
		}

		// Set the infix string of the evaluator object to the string inputted by the user
		evaluator->setInfix(userInput);

		// Call the evaluateExpression method and print the result
		std::cout << evaluator->evaluateExpression() << std::endl;
	}

	delete evaluator;

	return 0;

}
