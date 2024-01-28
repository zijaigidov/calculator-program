// io.h

#ifndef IO_H
#define IO_H

// Print the calculator menu.
void printCalculatorMenu();

// Get an operand from the user.
double getOperand();

// Get a mathematical operator from the user.
char getOperator();

// Print a mathematical operation.
void printOperation(double x, char op, double y);

#endif