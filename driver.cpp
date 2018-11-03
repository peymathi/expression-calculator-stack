#include "Add_Expr_Command.h"
#include "Multiply_Expr_Command.h"
#include "Divide_Expr_Command.h"
#include "Subtract_Expr_Command.h"
#include "Num_Expr_Command.h"
#include "Mod_Expr_Command.h"
#include "Array_Iterator.h"
#include "Stack_Expr_Command_Factory.h"

void runCommands(Array<Command*> commands, Stack<int> * numbers)
{
	for(Array_Iterator iter(commands); !iter.is_done(); iter.advance())
	{
		iter->evaluate(*numbers);
	}

	std::cout << numbers->top() << std::endl;
}

int main()
{
	// Test the command factory
	Command * cmd;
	Array<Command*> commands = new Array<Command*>(10);
	Stack<int> * numbers = new Stack<int>();
	Stack_Expr_Command_Factory * factory = new Stack_Expr_Command_Factory(*numbers);

	cmd = factory->create_num_command(10);
	commands[0] = cmd;

	cmd = factory->create_num_command(10);
	commands[1] = cmd;

	cmd = factory->create_num_command(10);
	commands[2] = cmd;

	cmd = factory->create_num_command(10);
	commands[3] = cmd;

	cmd = factory->create_add_command();
	commands[4] = cmd;

	cmd = factory->create_sub_command();
	commands[5] = cmd;

	cmd = factory->create_num_command(10);
	commands[6] = cmd;

	cmd = factory->create_num_command(10);
	commands[7] = cmd;

	cmd = factory->create_mod_command();
	commands[8] = cmd;

	cmd = factory->create_div_command();
	commands[9] = cmd;

	return 0;
}
