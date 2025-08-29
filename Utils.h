#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

int toInt(const std::string &s) {
    return std::stoi(s);
}

std::string toHex(int value) {
    std::stringstream ss;
    ss << std::uppercase << std::hex << value;
    return ss.str();
}