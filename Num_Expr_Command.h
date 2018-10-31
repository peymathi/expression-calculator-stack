/* I pledge that I have neither given nor received any help on this assignment */

/* This is a subclass of the Expr_Command class. This sum class implements the execute() method to
  add a number a number to the reference to the stack of current operands of the post fix expression

  This class contains the stack reference and the integer number as members */

class Num_Expr_Command : public Bin_Expr_Command
{
public:
  // Initializing constructor with the next operand to be pushed to the stack
  Num_Expr_Command(int nextInt)
  : nextInt_(nextInt)
  {}

  // Pushes the next integer in the expression to the stack of current operands. Declared virtual for further
  // extension if necessary
  virtual void execute(void)
  {
    currentOperands_.push(nextInt_);
  }

private:
  // Next Integer from postfix expression
  int nextInt;
};
