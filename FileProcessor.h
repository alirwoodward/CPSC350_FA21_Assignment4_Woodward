// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350-03
// Assignment 2

// FileProcessor.h
// This is a header file for FileProcessor.cpp that defines four public methods and includes iostream
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
