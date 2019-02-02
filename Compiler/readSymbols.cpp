//
//  readSymbols.cpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#include "readSymbols.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

SymbolReader::SymbolReader(string filename){
    this->filename = filename;
}

vector<string> SymbolReader::getSymbolFile(){
    readSymbols();
    return symbols;
}

void SymbolReader::readSymbols()
{
    string symbol;
    fstream symbolIn;
    symbolIn.open(filename,ios::in);
    if(!symbolIn.is_open()){
        cout<<"Failed to open file!";
    };
    while(symbolIn>>symbol)
    {
        symbols.push_back(symbol);
    }
    symbolIn.close();
}
