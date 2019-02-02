//
//  HashTheSymbol.cpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#include "HashTheSymbol.hpp"
#include <string>
#include <iostream>

using namespace std;
HashTheSymbol::HashTheSymbol(int hashSize){
    this->hashSize = hashSize;
}

int HashTheSymbol::getHashValue(string symbol){
    size_t value = hasher(symbol);
    //std::cout<<"size_t for "<<symbol<<" is "<<value<<"\n";
    return value%hashSize;
}
