#include "pprocess/commands/generate.h"
#include "pprocess/commands/preview.h"
#include "pprocess/parser/HelpPrinter.h"
#include "pprocess/parser/CliParser.h"

int main(int argc, const char **argv) {
    // initialize cli and parse the arguments
    initializeCli();
    parseCli(argc, argv);

    if (illegalArgument()) {
        showPreviewHelp(getIllegalName());
        exit(1);
    }

    auto command  = getCommandName();

    // show helper text based on the command
    if (shouldHelp() && strcmp("generate", getCommandName()) == 0) {
        showGenerateHelp();
        exit(0);
    } else if (shouldHelp() && strcmp("preview", getCommandName()) == 0) {
        showPreviewHelp();
        exit(0);
    } else if (shouldHelp()) {
        showGeneralHelp();
        exit(0);
    }

    // execute the command
    if (strcmp("generate", getCommandName()) == 0) {
        executeGenerate(getFlags(), enableVerbose());
    } else if (strcmp("preview", getCommandName()) == 0) {
        executePreview(getFlags(), enableVerbose());
    }
}
