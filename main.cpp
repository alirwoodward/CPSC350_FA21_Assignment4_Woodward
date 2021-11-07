// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	4- Fun With Stacks

#include "FileProcessor.h"
#include "RPNCalc.h"

//main method that takes in RPN or DNA through the command line
int main(int argc, char** argv){
  string programToRun = argv[1];
  FileProcessor f;
  RPNCalc r;
  //if statement that runs the RPN program through the RPNCalc file if the command line input is RPN
  if(programToRun == "RPN"){
    string operation;
    cout << "Please enter the operands and operator that you would like to excecute: ";
    getline(cin, operation);
    r.calculator(operation);
  //else if the command line input is DNA, runs the DNA program through the DNAComplement class
  }else if(programToRun == "DNA"){
    string dnaFilePath;
    cout << "Please enter the file path of your desired DNA sequence(s): ";
    cin >> dnaFilePath;
    f.processFile(dnaFilePath);
  //if command line input is not valid, tells user
  }else{
    cout << "Sorry! That is not a valid input, please try again" << endl;
  }

  return 0;
}
