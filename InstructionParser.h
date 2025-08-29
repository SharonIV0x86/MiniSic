#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "SYMTAB.h"
#include "AssemblerDirectives.h"
#include "Utils.h"
#include "Globals.h"
std::vector<std::vector<std::string>> instructionMatrix;

bool readAssemblyFile(std::string path)
{
    std::fstream asmInfile(path);
    if (!asmInfile) {
        std::cout << "Could Not Open the assembly file.\n";
        return false;
    }

    std::string line;
    while (std::getline(asmInfile, line))
    {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string word;
        while (ss >> word) tokens.push_back(word);

        std::string label = "", opcode = "", operand = "";
        if (tokens.size() == 3) { label = tokens[0]; opcode = tokens[1]; operand = tokens[2]; }
        else if (tokens.size() == 2) { opcode = tokens[0]; operand = tokens[1]; }
        else if (tokens.size() == 1) { opcode = tokens[0]; }

        if (opcode == "START") {
            processPseudoInstruction(LOCCTR, operand, opcode); // sets LOCCTR from operand (hex)
            if (!label.empty()) {
                addToSymbolTable(label, toHex(LOCCTR)); // PROG -> start address
            }
            if (!opcode.empty()) instructionMatrix.push_back({label, opcode, operand});
            continue;
        }

        if (!label.empty()) {
            addToSymbolTable(label, toHex(LOCCTR));
        }

        if (isPseudoInstruction(opcode)) {
            processPseudoInstruction(LOCCTR, operand, opcode); 
        } else if (!opcode.empty() && opcode != "END") {
            LOCCTR += 3; // normal SIC instruction
        }

        if (!opcode.empty()) {
            instructionMatrix.push_back({label, opcode, operand});
        }
    }
    for (auto &row : instructionMatrix)
        std::cout << "[" << row[0] << "] [" << row[1] << "] [" << row[2] << "]\n";

    std::cout << "Final LOCCTR: " << toHex(LOCCTR) << "\n";
    return true;
}
