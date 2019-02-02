//
//  symbolTable.hpp
//  Compiler
//
//  Created by Nic Pu on 1/30/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#ifndef symbolTable_hpp
#define symbolTable_hpp

#include <stdio.h>
#include "SubSymbolTable.hpp"
#include <string>
class SymbolTable{
public:
    int subTbSize;
    SymbolTable(int subTbSize);
    int nextSubTbNum;
    SymblTbForScope *CurrentSubTb;
    symbolCell *FindInCurrentScope(std::string symbol, int row);
    symbolCell *FindInAllScope(std::string symbol, int row);
    void AddSubTable();
    void DeleteCurrentSubTb();
    void PrintTable();
    void AddInCurrent(std::string symbol, int row);
private:
};

#endif /* symbolTable_hpp */
