//
//  SymbolTbOperator.hpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#ifndef SymbolTbOperator_hpp
#define SymbolTbOperator_hpp

#include <vector>
#include <stdio.h>
#include "symbolTable.hpp"
using namespace std;

class SymbolTbOperator{
public:
    SymbolTbOperator();
    void ConstuctSymbolTb(SymbolTable *symbolTable, string filename);
};

#endif /* SymbolTbOperator_hpp */
