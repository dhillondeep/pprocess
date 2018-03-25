/**
 * @file CliParser.h
 * @brief Parsers Commandline arguments and provide their values
 * @author Deep Dhillon
 * @date March 24, 2018
 */

#ifndef PPROCESS_CLIPARSER_H
#define PPROCESS_CLIPARSER_H

#include <map>
#include <string>

/**
 * Initialized commandFlags and adds their flags
 */
void initializeCli();

/**
 * Parses Commandline arguments and stores data in Cli packet
 *
 * @param argc number of arguments
 * @param argv arguments data
 */
void parseCli(int argc, const char **argv);

/**
 * This is true when help is to be shown
 *
 * @return true or false based on if help is needed to shown
 */
bool shouldHelp();

/**
 * This is true when verbose mode is on
 *
 * @return true or false based on if verbose mode is choosen to be on
 */
bool enableVerbose();

/**
 * Name of the command entered
 *
 * @return the name of the command
 */
const char *getCommandName();

/**
 * All the flags and their value for the command
 *
 * @return flag value
 */
std::map<std::string, std::string> getFlags();

/**
 * If there is anything illegal about the argument, this is true
 *
 * @return true or false based on if the argument is illegal
 */
bool illegalArgument();

/**
 * Name of the argument for the cli whole argument is illegal
 *
 * @return the name of the argument
 */
const char *getIllegalName();

#endif //PPROCESS_CLIPARSER_H
