//
//  HashTheSymbol.hpp
//  Compiler
//
//  Created by Nic Pu on 2/1/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#ifndef HashTheSymbol_hpp
#define HashTheSymbol_hpp

#include <stdio.h>
#include <string>

class HashTheSymbol{
public:
    HashTheSymbol(int hashSize);
    int getHashValue(std::string symbol);
private:
    int hashSize;
    std::hash<std::string> hasher;
};
#endif /* HashTheSymbol_hpp */
