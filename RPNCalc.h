// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	3- Game of life

#ifndef RPNCALC_H //header guard
#define RPNCALC_H //header guard

//header file for the Game class

#include <iostream>
#include <exception>

#include "GenStack.h"

using namespace std;

class RPNCalc{
  public:
    RPNCalc(); //default constructor
    ~RPNCalc(); //destructor
    void calculator(string operation);

  private:
    string operation;
    GenStack<int> *calcStack;
    string currNum;
    void modulous();
    void multiply();
    void addition();
    void subtraction();
    void division();
    int charToInt(string stringNum);
    void continueCalculator();
    int num1;
    int num2;
    int product;
    string stringNum;
    int number = 0;
};
#endif
