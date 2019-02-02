//
//  SymbolTbOperator.cpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#include "SymbolTbOperator.hpp"
#include "symbolTable.hpp"
#include "HashTheSymbol.hpp"
#include <vector>
#include <iostream>

using namespace std;
#include "readSymbols.hpp"

SymbolTbOperator::SymbolTbOperator(){}

void SymbolTbOperator::ConstuctSymbolTb(SymbolTable *symbolTable, string filename){
    SymbolReader symbolReader(filename);
    vector<string> symbols = symbolReader.getSymbolFile();
    HashTheSymbol hasher(symbolTable->subTbSize);
    for(auto i:symbols){
        if(i == "{"){
            symbolTable->AddSubTable();
        }
        else if(i == "}"){
            symbolTable->CurrentSubTb->printSubTb();
            symbolTable->DeleteCurrentSubTb();
        }
        else{
            symbolTable->AddInCurrent(i, hasher.getHashValue("i"));
        }
    }
}

