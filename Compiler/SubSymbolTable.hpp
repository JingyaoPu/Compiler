//
//  SubSymbolTable.hpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#ifndef SubSymbolTable_hpp
#define SubSymbolTable_hpp

#include <stdio.h>
#include <string>
struct symbolCell{
    std::string symbol = "";
    symbolCell *next = NULL;
};

class SymblTbForScope{
public:
    int SubTbNum;
    int TbSize;
    SymblTbForScope *nextSubTb = NULL;
    SymblTbForScope(int scopeNum, int TbSize);
    ~SymblTbForScope();
    symbolCell *Find(std::string symbol, int row);
    void Add(std::string symbol, int row);
    void printSubTb();
private:
    symbolCell **symbolTbForScope = NULL;
};

#endif /* SubSymbolTable_hpp */
