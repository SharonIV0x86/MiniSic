#include "InstructionParser.h"
#include "SYMTAB.h"
#include <iostream>
#include "Globals.h"
int main(){
    readAssemblyFile("testCode.asm");
    printSYMTAB();
    std::cout << "Starting address is: " << std::hex << startingAddress << "\n";
    std::cout << "Ending Address is: " << std::hex << endingAddress <<"\n";
    return 0;
}