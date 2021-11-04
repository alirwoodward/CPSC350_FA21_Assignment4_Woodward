#include "RPNCalc.h"
#include <unistd.h>

RPNCalc::RPNCalc(){
  //constructor
}

RPNCalc::~RPNCalc(){
  //destructor
}


void RPNCalc::calculator(string operation){
  calcStack = new GenStack<int>;
  //cout << operation << endl;
  for(int a = 0; a < operation.size(); ++a){
    // if it is a number
    if(int(operation[a]) >= 48 && int(operation[a]) <= 57 ){
      currNum += operation[a];
    }else if(int(operation[a]) == 32 && currNum != ""){
      calcStack->push(charToInt(currNum));
      currNum = "";
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

int RPNCalc::charToInt(string stringNum){
  number = 0;
  for(int n = 0; n < stringNum.size(); ++n){
    number *= 10;
    number += (int(stringNum[n]) - '0');
  }
  return number;
}

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
