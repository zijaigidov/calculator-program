// io.cpp

#include "io.h"
#include "math.h"

#include <iostream>
#include <limits>

void printCalculatorMenu()
{
	std::cout << "       CALCULATOR       \n"
				 "========================\n"
				 "Supported operations:   \n"
			 	 " - Addition (+)         \n"
				 " - Subtraction (-)      \n"
				 " - Multiplication (*, x)\n"
				 " - Division (/)         \n"
			 	 "========================\n";
}

static bool inputBufferIsEmpty()
{
	return std::cin.eof() || std::cin.peek() == '\n';
}

static void clearInputBuffer()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void handleFailedExtraction()
{
	std::cin.clear(); // Clear the error flag on std::cin
	clearInputBuffer();
}

double getOperand()
{
	while (true) // Keep looping until the user enters a valid number
	{
		double num{};
		std::cout << "Enter a number: ";
		std::cin >> num;

		// Check if extraction has failed
		if (!std::cin)
		{
			handleFailedExtraction();
			std::cout << "Please enter a valid number.\n";
			continue;
		}
		// Check if any characters haven't been extracted
		if (!inputBufferIsEmpty())
		{
			clearInputBuffer();
			std::cout << "Please enter a valid number.\n";
			continue;
		}

		return num;
	}
}

char getOperator()
{
	while (true) // Keep looping until the user enters a valid operator
	{
		char op{};
		std::cout << "Enter a mathematical operator: ";
		std::cin >> op;

		/* NOTE: There doesn't seem to be any need to check if extraction has failed (unlike in getOperand()) since
		 * extraction to a char (seemingly) can't fail.
		 */ 
		
		// Check if any characters haven't been extracted
		if (!inputBufferIsEmpty())
		{
			clearInputBuffer();
			std::cout << "Please enter a valid operator.\n";
			continue;
		}

		// Check if the operator is one of the supported operators
		using namespace MathOperations;
		switch (op)
		{
		case addition:
		case subtraction:
		case multiplicationStar:  // '*' character
		case multiplicationCross: // 'x' character
		case division:
			return op;
		default:
			std::cout << "Please enter a valid operator.\n";
		}
	}
}

void printOperation(double x, char op, double y)
{
	using namespace MathOperations;

	switch (op)
	{
	case addition:
		std::cout << x << " + " << y << " = " << x + y << '\n';
		break;

	case subtraction:
		std::cout << x << " - " << y << " = " << x - y << '\n';
		break;

	case multiplicationStar:
	case multiplicationCross:
		std::cout << x << ' ' << op << ' ' << y << " = " << x * y << '\n';
		break;

	case division:
	{
		if (y == 0)
		{
			std::cout << "Error: cannot divide by zero\n";
			break;
		}

		std::cout << x << " / " << y << " = " << x / y << '\n';
		break;
	}
	}
}

bool keepCalculating()
{
	while (true)
	{
		char ans{};
		std::cout << "Would you like to keep calculating? (y/n): ";
		std::cin >> ans;

		if (!inputBufferIsEmpty())
		{
			clearInputBuffer();
			std::cout << "Please enter 'y' or 'n'\n";
			continue;
		}

		switch (ans)
		{
		case 'y':
			std::cout << '\n';
			return true;
		case 'n':
			std::cout << '\n';
			return false;
		default:
			std::cout << "Please enter 'y' or 'n'\n";
		}
	}
}