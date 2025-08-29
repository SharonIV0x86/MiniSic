#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::vector<std::string>> instructionMatrix;
int LOCCTR = 0;
bool readAssemblyFile(std::string path)
{
    std::fstream asmInfile(path);
    if (!asmInfile)
    {
        std::cout << "Could Not Open the assembly file.\n";
        return false;
    }
    std::string line;

    while (std::getline(asmInfile, line))
    {
        std::stringstream ss(line);
        std::vector<std::string> tokens;
        std::string word;
        
        while (ss >> word)
        {
            tokens.push_back(word);
        }

        std::string label = "", opcode = "", operand = "";
        
        if (tokens.size() == 3)
        {
            label = tokens[0];
            opcode = tokens[1];
            operand = tokens[2];
        }
        else if (tokens.size() == 2)
        {
            opcode = tokens[0];
            operand = tokens[1];
        }
        else if (tokens.size() == 1)
        {
            opcode = tokens[0];
        }
        if (!opcode.empty())
        {
            instructionMatrix.push_back({label, opcode, operand});
        }
    }

    for (auto &row : instructionMatrix)
    {
        std::cout << "[" << row[0] << "] [" << row[1] << "] [" << row[2] << "]\n";
    }
    return true;
}