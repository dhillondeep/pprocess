#ifndef PPROCESS_GENERATE_H
#define PPROCESS_GENERATE_H

#include <map>
#include <string>
#include <iostream>

void executeGenerate(std::map<std::string, std::string> &flags, bool verbose) {
    std::cout << "Generate yay: " << flags.size() << std::endl;
}

#endif //PPROCESS_GENERATE_H
