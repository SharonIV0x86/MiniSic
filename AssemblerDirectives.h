#include <unordered_map>
#include <string>


std::unordered_map<std::string, bool> asmDir = {
    {"START", true},
    {"END", true},
    {"BYTE", true},
    {"WORD", true},
    {"RESB", true},
    {"RESW", true},
};

bool isPseudoInstruction(std::string a){
    if(asmDir.find(a) != asmDir.end()) return true;
    return false;
}