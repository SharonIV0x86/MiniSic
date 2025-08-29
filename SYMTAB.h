#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
std::unordered_map<std::string, std::string> SYMTAB;

void printSYMTAB(){
    std::cout << "SYMBOL Table is as follows\n";
    for(const auto[first, second]: SYMTAB){
        std::cout << first << "\t" << second << "\n"; 
    }
}

void addToSymbolTable(std::string label, std::string address)
{
    if (SYMTAB.find(label) != SYMTAB.end())
        return;
    SYMTAB[label] = address;
}
