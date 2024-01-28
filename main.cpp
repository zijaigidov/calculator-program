// main.cpp:

#include "io.h"
#include <iostream>

int main()
{
    printCalculatorMenu();
    auto firstOperand { getOperand() };
    auto mathOperator { getOperator() };
    auto secondOperand { getOperand() };
    printOperation(firstOperand, mathOperator, secondOperand);

    return 0;
}