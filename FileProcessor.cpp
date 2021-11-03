// Ali Woodward
// 2385718
// alwoodward@chapman.edu
// CPSC 350-03
// Assignment 2

// FileProcessor.cpp
// This file contains a constructor, destructor, and a method named processFile that takes in the names of input and output files
// and then reads from teh input file, calls the correct other classes to translate the file, and then prints the translated words
// into the output file

#include "FileProcessor.h"

// default constructor
FileProcessor::FileProcessor(){
  //default constructor body - empty
}

// deconstructor
FileProcessor::~FileProcessor(){
  //deconstuctor - empty
}

//processFile method takes in an input file, opens the file for reading, reads its contents, then translates it and prints it to the output file
void FileProcessor::processFile(string inputFile){
  //open file for writing

  fstream complement;
  complement.open("dnaoutput.txt", ios::out);

  //open file for reading
  fstream ogDNA;
  ogDNA.open(inputFile, ios::in);

  string currLine;
  if (ogDNA.is_open())
  {
    while ( getline (ogDNA,currLine) )
    {
      complement << "Sequence: " + currLine + "\n";
      string complementString = d.getComplement(currLine);
      string reversedComplement = d.reverseComplement(complementString);
      complement << "Complement: " + complementString + "\n";
      complement << "Reverse complement: " + reversedComplement + "\n\n";
    }
    ogDNA.close();
  }

  complement.close();
}
