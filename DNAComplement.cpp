
#include "DNAComplement.h"

DNAComplement::DNAComplement(){
  //empty constructor
}

DNAComplement::~DNAComplement(){
  //empty destructor
}

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


string DNAComplement::reverseComplement(string complement){
  if(complement == "Invalid DNA sequence."){
    return complement;
  }else{
    reverseComp = "";
    DNAStack = new GenStack<char>;
    for(int i = 0; i < complement.size(); ++i){
      DNAStack->push(complement[i]);
    }

    char na;
    while(!DNAStack->isEmpty()){
      reverseComp += DNAStack->pop();
    }
    return reverseComp;
  }
}
