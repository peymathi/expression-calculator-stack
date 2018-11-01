#include "Add_Expr_Command.h"
#include "Multiply_Expr_Command.h"
#include "Divide_Expr_Command.h"
#include "Subtract_Expr_Command.h"
#include "Num_Expr_Command.h"
#include "Mod_Expr_Command.h"
#include "Array_Iterator.h"

int main()
{
	// Test the iterator object

	// Testing with primitive data type
	Array<int> * numbers = new Array<int>(10);

	for(Array_Iterator<int> numberIter(*numbers); !numberIter.is_done(); numberIter.advance())
	{
		*numberIter = 1;
	}

	for(Array_Iterator<int> numberIter(*numbers); !numberIter.is_done(); numberIter.advance())
	{
		std::cout << *numberIter << std::endl;
	}

	return 0;
}
