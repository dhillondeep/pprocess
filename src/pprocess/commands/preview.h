#ifndef PPROCESS_PREVIEW_H
#define PPROCESS_PREVIEW_H

#include <string>
#include <map>
#include <iostream>

void executePreview(std::map<std::string, std::string> flags, bool verbose) {
    std::cout << "Preview yay: " << flags.size() << std::endl;
}

#endif //PPROCESS_PREVIEW_H
