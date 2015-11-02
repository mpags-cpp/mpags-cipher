#include "ProcessCommandLine.hpp"

#include <string>
#include <iostream>

bool processCommandLine(int argc, char* argv[],
                        bool& requiresHelp,
                        bool& requiresVersion,
                        std::string& inputFile,
                        std::string& outputFile,
                        std::string& cipherKey,
                        bool& cipherDecrypt) {
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
    else if (argvString == "-k") {
      // Handle cipher key option
      // Next element is key unless -k is the last argument
      // Always treat next element in argv as key as even things like
      // '--help' *might* be valid!
      if (i == argc-1) {
        std::cerr << "-k requires a filename argument\n";
        return false;
      }
      else {
        cipherKey = argv[i+1];
        i += 1;
      }
    }
    else if (argvString == "--decrypt") {
      cipherDecrypt = true;
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


void doPrintCommandLineHelp() {
  // Line splitting for readability
  std::cout
      << "Usage: mpags-cipher [-i <file>] [-k KEY] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "  -k KEY           Use KEY as key for cipher\n"
      << "                   An empty key is used if not supplied\n\n"
      << "  --decrypt        Decrypt input text using KEY instead of\n"
      << "                   encrypting\n\n";
}


void doPrintCommandLineVersion() {
    std::cout << "0.1.0\n";
}

