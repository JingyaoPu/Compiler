//
//  main.cpp
//  Compiler
//
//  Created by Nic Pu on 1/30/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#include <iostream>
#include "symbolTable.hpp"
#include "SymbolTbOperator.hpp"

int main(int argc, const char * argv[]) {
    int tableSize = 4;
    SymbolTable tb(tableSize);
    string filename = "symbols.txt";
    SymbolTbOperator SymbolTbOperator;
    SymbolTbOperator.ConstuctSymbolTb(&tb, filename);
    
    
   /**  test for subTb*************
    
    SymblTbForScope tb(0,4);
    std::string a= "abc";
    std::string b= "##";
    std::string c= "98";
    tb.Add(a, 0);
    tb.Add(b, 2);
    tb.Add(c, 3);
    symbolCell *p = tb.Find(a, 0);
    symbolCell *p2 = tb.Find(b, 2);
    symbolCell *p3 = tb.Find(c, 3);
    std::cout << p->symbol<<"\n"<<p2->symbol<<"\n"<<p3->symbol;
    **/
    return 0;
}
