// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	4- Fun With Stacks

#ifndef DNACOMPLEMENT_H //header guard
#define DNACOMPLEMENT_H //header guard

//header file for the DNAComplement class

#include <iostream>
#include <exception>

#include "GenStack.h"

using namespace std;

class DNAComplement{
  public:
    DNAComplement(); //default constructor
    ~DNAComplement(); //destructor

    string reverseComp;
    string getComplement(string dna);
    string reverseComplement(string complement);
    GenStack<char> *DNAStack;
};
#endif
