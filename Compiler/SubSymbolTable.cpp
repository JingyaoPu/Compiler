//
//  SubSymbolTable.cpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//
#include <iostream>
#include "SubSymbolTable.hpp"

SymblTbForScope::SymblTbForScope(int SubTbNum, int TbSize){
    this->SubTbNum = SubTbNum;
    this->TbSize = TbSize;
    symbolTbForScope = new symbolCell*[TbSize];
    for(int i=0;i<TbSize;i++){
        symbolTbForScope[i] = NULL;
    }
}

SymblTbForScope::~SymblTbForScope(){
    delete [] this->symbolTbForScope;
}

symbolCell *SymblTbForScope::Find(std::string symbol, int row){
    symbolCell *foundSymbl = NULL;
    symbolCell *currentCell;
    if (symbolTbForScope[row] != NULL){
        currentCell = symbolTbForScope[row];
        do{
            if(currentCell->symbol == symbol){
                foundSymbl = currentCell;
                break;
            }
            currentCell = currentCell->next;
        }while(currentCell != (symbolCell*)NULL);
    }
    return foundSymbl;
}

void SymblTbForScope::Add(std::string symbol, int row){
    symbolCell *newCell;
    newCell = new struct symbolCell;
    newCell->symbol = symbol;
    
    //add onto the head of the list
    newCell->next = symbolTbForScope[row];
    symbolTbForScope[row] = newCell;
    
    /* Add onto the tail of the list
    if (symbolTbForScope[row] != NULL){
        symbolCell *currentCell = symbolTbForScope[row];
        while(currentCell->next != NULL){
            currentCell = currentCell->next;
        }
        currentCell->next = newCell;
    }else{
        symbolTbForScope[row] = newCell;
    }
    */
}

void SymblTbForScope::printSubTb(){
    std::cout<<"scope"<<this->SubTbNum<<":";
    for(int i=0;i<this->TbSize;i++){
        if(this->symbolTbForScope[i] != NULL){
            symbolCell *printCell = symbolTbForScope[i];
            while(printCell != NULL){
                std::cout<<printCell->symbol<<" ";
                printCell = printCell->next;
            }
        }
    }
    std::cout<<"\n";
}
