#pragma once
#include <unordered_map>
#include <string>
#include <vector>
std::unordered_map<std::string, std::string> SYMTAB;

void buildSymbolTable(std::vector<std::vector<std::string>> instructionMatrix){
    int size = instructionMatrix.size() - 1; 
    // [label] [opcode] [operand].
    for(int i = 0; i < size; i++){
        std::string label = instructionMatrix[i][0];
        std::string opcode = instructionMatrix[i][1];
        std::string operand = instructionMatrix[i][2];

        if(!label.empty()){
            SYMTAB[label]
        }
        
    }
}