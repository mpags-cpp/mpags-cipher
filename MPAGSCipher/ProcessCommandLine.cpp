#include "ProcessCommandLine.hpp"

#include <string>
#include <iostream>

bool processCommandLine(int argc, char* argv[],
                        bool& requiresHelp,
                        bool& requiresVersion,
                        std::string& inputFile,
                        std::string& outputFile) {
  // Process command line arguments - ignore zeroth element of argv
  // as we know this to be the program name and don't need to worry
  // about it
  for (int i {1}; i < argc; ++i) {
    std::string argvString(argv[i]);

    if (argvString == "-h" || argvString == "--help") {
      requiresHelp = true;
    }
    else if (argvString == "--version") {
      requiresVersion = true;
    }
    else if (argvString == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      // Do not handle case of, e.g. "-i -o" as -o is a valid filename!
      if (i == argc-1) {
        std::cerr << "-i requires a filename argument\n";
        // return false to indicate failure
        return false;
      }
      else {
        // Got filename, so assign value and advance past it.
        inputFile = argv[i+1];
        i += 1;
      }
    }
    else if (argvString == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      // Do not handle case of, e.g. "-o -h" as -h is a valid filename!
      if (i == argc-1) {
        std::cerr << "-o requires a filename argument\n";
        // return false indicate failure
        return false;
      }
      else {
        // Got filename, so assign value and advance past it.
        outputFile = argv[i+1];
        i += 1;
      }
    }
    else {
      // Have an unknown flag so output error message and return false
      // to indicate failure
      std::cerr << "[error] unknown argument '" << argvString << "'\n";
      return false;
    }
  }

  return true;
}

