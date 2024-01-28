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
				 " - Modulo (%)           \n"
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
			std::cout << "Please enter a valid number.\n\n";
			continue;
		}
		// Check if any characters haven't been extracted
		if (!inputBufferIsEmpty())
		{
			clearInputBuffer();
			std::cout << "Please enter a valid number.\n\n";
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
			std::cout << "Please enter a valid operator.\n\n";
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
		case modulo:
			return op;
		default:
			std::cout << "Please enter a valid operator.\n\n";
		}
	}
}