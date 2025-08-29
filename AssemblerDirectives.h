#pragma once
#include <unordered_map>
#include <string>
#include "Utils.h"
#include "InstructionParser.h"
#include "Globals.h"
std::unordered_map<std::string, bool> asmDir = {
    {"START", true},
    {"END", true},
    {"BYTE", true},
    {"WORD", true},
    {"RESB", true},
    {"RESW", true},
};

bool isPseudoInstruction(std::string a)
{
    if (asmDir.find(a) != asmDir.end())
        return true;
    return false;
}
void processPseudoInstruction(int &LOCCTR, const std::string &operand, const std::string &opcode)
{
    if (opcode == "START")
    {
        if (!operand.empty())
            LOCCTR = std::stoi(operand, nullptr, 16); 
        else
            LOCCTR = 0;
        startingAddress = LOCCTR;
        
    }
    else if (opcode == "END")
    {
        endingAddress = LOCCTR;
    }
    else if (opcode == "WORD")
    {
        LOCCTR += 3; 
    }
    else if (opcode == "RESW")
    {
        LOCCTR += 3 * std::stoi(operand); 
    }
    else if (opcode == "RESB")
    {
        LOCCTR += std::stoi(operand); 
    }
    else if (opcode == "BYTE")
    {
        if (operand[0] == 'C' && operand[1] == '\'')
        {
            size_t len = operand.size() - 3; // e.g. C'Z'
            LOCCTR += len;
        }
        else if (operand[0] == 'X' && operand[1] == '\'')
        {
            // each 2 hex digits = 1 byte
            size_t len = operand.size() - 3;
            LOCCTR += (len + 1) / 2;
        }
    }
}
