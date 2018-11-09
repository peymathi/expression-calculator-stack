#include "Infix_Expr_Evaluator.h"

// COMMENT: Instead of using C functions to implement parts of the
// calculator. It would be better suited to use a Wrapper Facade.

// REPLY: Created a wrapper class named Infix_Expr_Evaluator to allow the client ease of use

// COMMENT: Improve the design of your commands to reduce the design
// complexity of this method. Right now, there are too many if-else
// statements, and a lot of duplicate code.

// REPLY: Response to this comment is addressed in the new wrapper class. Solution is in comment "REPLY1"

// COMMENT: I do not see where you are taking into account the precedence
// of the operator during the conversion process.

// REPLY: Response to this comment is addressed in the new wrapper class. Solution is in comment "REPLY2"

int main()
{
	std::string userInput;

	Infix_Expr_Evaluator * evaluator = new Infix_Expr_Evaluator();

	while(true)
	{
		std::cout << "Enter an Infix Expression or enter QUIT to quit: ";
		std::cin >> userInput;

		if(userInput == "QUIT")
		{
			break;
		}

		// Set the infix string of the evaluator object to the string inputted by the user
		evaluator->setInfix(userInput);

		// Call the evaluateExpression method and print the result
		std::cout << evaluator->evaluateExpression() << std::endl;
	}

	delete Infix_Expr_Evaluator;

}
