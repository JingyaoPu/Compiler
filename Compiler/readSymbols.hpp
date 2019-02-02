//
//  readSymbols.hpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#ifndef readSymbols_hpp
#define readSymbols_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class SymbolReader{
public:
    SymbolReader(string filename);
    vector<string> getSymbolFile();
private:
    string filename;
    vector<string> symbols;
    void readSymbols();
};
#endif /* readSymbols_hpp */
