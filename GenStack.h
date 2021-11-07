// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	4- Fun With Stacks

//GenStack.h is a file that contains all functions of a working stack
//contains methods: push, pop, peek, isEmpty, isFull and getSize

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>

#include "LinkedList.h"
using namespace std;

template <class type>

class GenStack{
  public:
    GenStack(); //default constructor
    ~GenStack(); //destructor

    //core functions
    void push(type data);
    type pop();

    //aux helper functions
    type peek();
    bool isEmpty();
    bool isFull();
    int getSize();
    DoublyLinkedList<type> *ll;

    private:
      //DoublyLinkedList<type> *ll;
      int mSize;
      int top;
};



template<class type>
GenStack<type>::GenStack(){
  //mSize = 128;
  //top = -1;
  //myArray = new type[mSize];
  ll = new DoublyLinkedList<type>;
}


template <class type>
GenStack<type>::~GenStack(){
  cout << "stack destructed" << endl;
  // need to delete linked list stack
  delete ll;
}

template <class type>
void GenStack<type>::push(type data){
  //check if full
  if(isFull()){
    throw runtime_error("stack is full!!!");
  }
  ll->insertBack(data);
  //myArray[++top] = data;
}

template <class type>
type GenStack<type>::pop(){
  //check if empty
  //cout << "get here?" << endl;
  if(isEmpty()){
    throw runtime_error("Invalid input. Please check the format of what you have entered and try again.");
  }
  //cout << "what about here" << endl;
  return ll->removeBack();
}

template <class type>
type GenStack<type>::peek(){
  if(isEmpty()){
    throw runtime_error("stack is empty can NOT peek!!");
  }
  //// do this
  return ll->peek();
}

//dont actualy think i need this because its a linked list
template <class type>
bool GenStack<type>::isFull(){
  return(top == mSize -1);
}


template <class type>
bool GenStack<type>::isEmpty(){
  return ll->isEmpty();
}

template <class type>
int GenStack<type>::getSize(){
  return(top = 1);
}

#endif //header guard
