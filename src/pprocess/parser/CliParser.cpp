/**
 * @file CliParser.cpp
 * @brief Parsers Commandline arguments and provide their values
 * @author Deep Dhillon
 * @date March 24, 2018
 */


#include "CliParser.h"
#include <list>

/**
 * CliData class is packet that contains cli info for this project
 */
class CliData {
public:
    const char *command = "\0";

    // boolean flags
    bool help = false;
    bool verbose = false;

    // illegal
    bool illegalArgs = false;
    const char *illegalName = "\0";

    std::map<std::string, std::string> flagValues;

    void addFlagValue(const char *name, const char *value) {
        flagValues.insert(std::pair<std::string, std::string>(name, value));
    }
};

std::map<std::string, std::list<std::string>> commandFlags;     /// flags acceptable for commands
CliData cliData;                                                /// cli packet


void initializeCli() {
    std::list<std::string> generateList = {"--file"};
    std::list<std::string> previewList = {"--file"};

    commandFlags["generate"] = generateList;
    commandFlags["preview"] = previewList;
}

void parseCli(int argc, const char **argv) {
    if (argc <= 1) {
        cliData.help = true;
    } else {
        for (int i = 1; i <  argc; ++i) {
            const char *value = argv[i];

            if (strcmp("-h", value) == 0 || strcmp("-help", value) == 0) {
                cliData.help = true;
            } else if (strcmp("-v", value) == 0 || strcmp("-verbose", value) == 0) {
                cliData.verbose = true;
            } else if (value[0] != '-' && commandFlags.count(std::string{value})) {
                cliData.command = value;
            } else if (value[0] == '-' && value[1] == '-'){
                if ((i + 1) >= argc || argv[i+1][0] == '-') {
                    cliData.illegalArgs = true;
                    cliData.illegalName = value;
                    return;
                }

                cliData.addFlagValue(value, argv[i+1]);
                ++i;
            } else {
                cliData.illegalArgs = true;
                cliData.illegalName = value;
                return;
            }
        }
    }

    // check if appropriate flags are there for the specific command
    std::map<std::string, std::string>::iterator it;

    for (it = cliData.flagValues.begin(); it != cliData.flagValues.end(); it++ ) {
        auto command = getCommandName();
            auto flag = it->first;
            auto g = commandFlags;
            std::list<std::string> cmdList = commandFlags.find(command)->second;

            if (std::find(cmdList.begin(), cmdList.end(), flag) == cmdList.end()) {
                cliData.illegalArgs = true;
                cliData.illegalName = flag.c_str();
                return;
            }
    }
}

bool shouldHelp() {
    return cliData.help;
}

bool enableVerbose() {
    return cliData.verbose;
}

const char *getCommandName() {
    return cliData.command;
}

std::map<std::string, std::string> getFlags() {
    return cliData.flagValues;
}

bool illegalArgument() {
    return cliData.illegalArgs;
}

const char *getIllegalName() {
    return cliData.illegalName;
}
