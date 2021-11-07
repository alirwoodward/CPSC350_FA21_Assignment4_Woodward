// Ali Woodward
// 2385718
// alwoodwadr@chapman.edu
// CPSC 350 Section 03
// Assignment	4- Fun With Stacks

// DNAComplement.cpp
// This file contains a constructor, destructor, a method named getComplement that takes in a DNA sequence from a file as input and
// returns the complement sequence of DNA as well as a method reverseComplement that takes in the complement string of DNA as input and returns the reverse complement

#include "DNAComplement.h"


//constructor method
DNAComplement::DNAComplement(){
  //empty constructor
}

//destructor method
DNAComplement::~DNAComplement(){
  //empty destructor
}

//getComplement method
//paremeter: string dna is the sequence of dna sent from file FileProcessor
//returns string of the complement DNA

string DNAComplement::getComplement(string dna){
  string complementDNA = "";
  if(dna == ""){
    complementDNA = "Invalid DNA sequence.";
  }else{
    for(int i = 0; i < dna.size(); ++i){
      if(dna[i] == 'A'){
        complementDNA += 'T';
      }else if(dna[i] == 'T'){
        complementDNA += 'A';
      }else if(dna[i] == 'C'){
        complementDNA += 'G';
      }else if(dna[i] == 'G'){
        complementDNA += 'C';
      }else{
        complementDNA = "Invalid DNA sequence.";
        break;
      }
    }
  }
  return complementDNA;
}

//reverseComplement method
//paremeter: string complement is the string of complement DNA that was previously returned by the above method
//uses a the GenStack class to use a stack to perform the reverse complement

string DNAComplement::reverseComplement(string complement){
  if(complement == "Invalid DNA sequence."){
    return complement;
  }else{
    reverseComp = "";
    DNAStack = new GenStack<char>;
    //for loop to push each letter into the stack
    for(int i = 0; i < complement.size(); ++i){
      DNAStack->push(complement[i]);
    }

    char na;
    //while loop to pop each letter from the stack to add it to a string representing the reverse complement
    while(!DNAStack->isEmpty()){
      reverseComp += DNAStack->pop();
    }
    return reverseComp;
  }
}
