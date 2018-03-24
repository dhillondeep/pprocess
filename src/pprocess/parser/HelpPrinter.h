/**
 * @file HelpPrinter.h
 * @brief Printer contains the text for Help commands
 * @author Deep Dhillon
 * @date March 24, 2018
 */


#ifndef PPROCESS_PRINTER_H
#define PPROCESS_PRINTER_H

#include <iostream>

/**
 * Shows help text for the general program
 */
void showGeneralHelp() {
    std::cout << "Use the benefits of preprocessor in any text file or a programming language" << std::endl;
    std::cout << std::endl;

    std::cout << "Usage: pprocess <command> [options]" << std::endl << std::endl;

    std::cout << "Commands:" << std::endl << std::endl;
    std::cout << "    pprocess generate [options]" << std::endl;
    std::cout << "        Runs preprocessor and generates files with the result." << std::endl << std::endl;

    std::cout << "    pprocess preview [options]" << std::endl;
    std::cout << "        Previews the result of running preprocessor." << std::endl << std::endl;

    std::cout << "Global options:" << std::endl;
    std::cout << "-h, --help            Print this usage information." << std::endl;
    std::cout << "-v, --verbose         Noisy logging, including all shell commands executed." << std::endl;
}

/**
 * Shows help text for command: generate
 */
void showGenerateHelp() {
    std::cout << "Runs preprocessor on the text and generates text with identifiers replaced." << std::endl;
    std::cout << std::endl;

    std::cout << "Usage: pprocess generate [options]" << std::endl;
    std::cout << "-h, --help            Print this usage information." << std::endl;
    std::cout << "-v, --verbose         Noisy logging, including all shell commands executed." << std::endl;
    std::cout << "-f, --file            Generate and process a single file." << std::endl;
}

/**
 * Shows help text for command: preview
 */
void showPreviewHelp() {
    std::cout << "Previews the result of preprocessor before identifiers are replaced." << std::endl;
    std::cout << std::endl;

    std::cout << "Usage: pprocess generate [options]" << std::endl;
    std::cout << "-h, --help            Print this usage information." << std::endl;
    std::cout << "-v, --verbose         Noisy logging, including all shell commands executed." << std::endl;
    std::cout << "-f, --file            Preview a single file." << std::endl;
}

#endif //PPROCESS_PRINTER_H
