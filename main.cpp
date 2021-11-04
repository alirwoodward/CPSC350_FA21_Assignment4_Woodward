// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	3- Game of life

#include "FileProcessor.h"
#include "RPNCalc.h"

//main method that takes in input file and output file through the command line
int main(int argc, char** argv){
  string programToRun = argv[1];
  FileProcessor f;
  RPNCalc r;
  if(programToRun == "RPN"){
    string operation;
    cout << "Please enter the operands and operator that you would like to excecute: ";
    getline(cin, operation);
    r.calculator(operation);
  }else if(programToRun == "DNA"){
    string dnaFilePath;
    cout << "Please enter the file path of your desired DNA sequence(s): ";
    cin >> dnaFilePath;
    f.processFile(dnaFilePath);

  }else{
    cout << "Sorry! That is not a valid input, please try again" << endl;
  }

  return 0;
}
