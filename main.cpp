// main.cpp:

#include "io.h"
#include <iostream>

int main()
{
    printCalculatorMenu();
    do
    {
        auto firstOperand{ getOperand() };
        auto mathOperator{ getOperator() };
        auto secondOperand{ getOperand() };
        printOperation(firstOperand, mathOperator, secondOperand);
    } while (keepCalculating());

    return 0;
}