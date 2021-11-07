// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	4- Fun With Stacks

// FileProcessor.h
// This is a header file for FileProcessor.cpp that defines three public methods and includes iostream
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "DNAComplement.h"
#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor{

public:
  FileProcessor(); //default constructor
  ~FileProcessor(); //destructor
  void processFile(string inputFile); //takes in an input file, translates its contents, produces an output file
  DNAComplement d;
};
#endif
