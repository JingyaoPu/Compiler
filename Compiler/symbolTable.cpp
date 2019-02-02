//
//  symbolTable.cpp
//  Compiler
//
//  Created by Nic Pu on 1/30/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//
#include <iostream>
#include "symbolTable.hpp"
#include "SubSymbolTable.hpp"

SymbolTable::SymbolTable(int subTbSize) {
    this->nextSubTbNum = 0;
    this->subTbSize = subTbSize;
    this->CurrentSubTb = NULL;
}

symbolCell *SymbolTable::FindInCurrentScope(std::string symbol, int row){
    return this->CurrentSubTb->Find(symbol, row);
}

symbolCell *SymbolTable::FindInAllScope(std::string symbol, int row){
    symbolCell *FoundCell = NULL;
    SymblTbForScope *currentSearchSubTb = this->CurrentSubTb;
 
    do{
        FoundCell = currentSearchSubTb->Find(symbol, row);
        currentSearchSubTb = currentSearchSubTb->nextSubTb;
    }while((FoundCell == NULL) && (currentSearchSubTb != NULL));
    
    return FoundCell;
}

void SymbolTable::AddSubTable(){
    SymblTbForScope *NewSubTb = new SymblTbForScope(this->nextSubTbNum,this->subTbSize);
    this->nextSubTbNum++;
    NewSubTb->nextSubTb = this->CurrentSubTb;
    this->CurrentSubTb = NewSubTb;
}

void SymbolTable::DeleteCurrentSubTb(){
    SymblTbForScope *SubTbToDelete = this->CurrentSubTb;
    this->CurrentSubTb = this->CurrentSubTb->nextSubTb;
    SubTbToDelete->~SymblTbForScope();
}

void SymbolTable::AddInCurrent(std::string symbol, int row){
    if(this->FindInCurrentScope(symbol, row) == NULL){
        this->CurrentSubTb->Add(symbol, row);
    }
}

void SymbolTable::PrintTable(){
    if (this->CurrentSubTb != NULL){
        SymblTbForScope *CurrentPrintTb = this->CurrentSubTb;
        do{
            CurrentPrintTb->printSubTb();
            CurrentPrintTb = CurrentPrintTb->nextSubTb;
            std::cout<<"\n";
        }while(CurrentPrintTb != NULL);
    }
    else{
        std::cout<<"SybolTable is empty.";
    }
}
