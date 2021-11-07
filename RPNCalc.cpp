// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	4- Fun With Stacks


//The RPNCalc class carrys out the functions of an RPN calculator
#include "RPNCalc.h"
#include <unistd.h>

//constructor
RPNCalc::RPNCalc(){
  //constructor
}

//destructor
RPNCalc::~RPNCalc(){
  //destructor
}

// calculator method is the main function that is called to use the RPNCalc class
//paremeter: string operation takes in the operation to be done in RPN format in order to function properly

void RPNCalc::calculator(string operation){
  calcStack = new GenStack<int>;
  //cout << operation << endl;
  for(int a = 0; a < operation.size(); ++a){
    // else-if statements that use the ascii values of the input string's individual chars

    //if the char is a number based on its ascii value, adds the number to the currNum string in case the number is multiple digits long
    if(int(operation[a]) >= 48 && int(operation[a]) <= 57 ){
      currNum += operation[a];
    //if the char is a space and currNum is not empty, the int value of the currNum string is found and addded to the stack and currNum string becomes empty again
    }else if(int(operation[a]) == 32 && currNum != ""){
      calcStack->push(charToInt(currNum));
      currNum = "";
    //the rest of the if statements see if the char is an operator and call the appropriate function to carry out the operation
    }else if(int(operation[a] == 37)){
        modulous();
    }else if(int(operation[a] == 42)){
      multiply();
    }else if(int(operation[a] == 43)){
      addition();
    }else if(int(operation[a] == 45)){
      subtraction();
    }else if(int(operation[a] == 47)){
      division();
    }
  }


  cout << "\nThe result of your operation is: ";
  cout << calcStack->pop() << endl;

  continueCalculator();
}


// the following methods modulous, addition, subtraction, multiply, and division perform the stated operation at hand
void RPNCalc::modulous(){
  product = 0;
  num1 = calcStack->pop();
  num2 = calcStack->pop();
  product = num1 % num2;
  calcStack->push(product);
}

void RPNCalc::addition(){
  product = 0;
  num1 = calcStack->pop();
  num2 = calcStack->pop();
  product = num1 + num2;
  calcStack->push(product);
}

void RPNCalc::subtraction(){
  product = 0;
  num1 = calcStack->pop();
  num2 = calcStack->pop();
  product = num2 - num1;
  calcStack->push(product);
}

void RPNCalc::multiply(){
  product = 0;
  num1 = calcStack->pop();
  num2 = calcStack->pop();
  product = num1 * num2;
  calcStack->push(product);
}

void RPNCalc::division(){
  product = 0;
  num1 = calcStack->pop();
  num2 = calcStack->pop();
  product = num2 / num1;
  calcStack->push(product);
}


//charToInt takes in the string version of a number that was recieved as input to the calculator function
//this string number is then converted to the proper integer version of the current number
int RPNCalc::charToInt(string stringNum){
  number = 0;
  for(int n = 0; n < stringNum.size(); ++n){
    number *= 10;
    number += (int(stringNum[n]) - '0');
  }
  return number;
}


//the continueCalculator method is called at the end of the calculator method to give users the option to continue making calculations or exit the program.
void RPNCalc::continueCalculator(){
  sleep(2);

  string contCalc = "";
  cout << "\nWould you like to perform another calculation? Enter 'Y' for YES and anything else to exit the program: ";
  getline(cin,contCalc);
  if(contCalc == "Y"){
    string operate;
    cout << "Please enter the operands and operator that you would like to excecute with a space in between each operand/operator: ";
    getline(cin, operate);
    cout << operate << endl;
    calculator(operate);
  }else{
    cout << "Program exited..." << endl;
  }

}
