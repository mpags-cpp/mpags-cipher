// Standard Library includes
#include <iostream>
#include <string>

// Our project headers
#include "ProcessCommandLine.hpp"
#include "TransformChar.hpp"

//! Main function of the mpags-cipher program
int main(int argc, char* argv[]) {
  // Command line inputs
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  bool commandLineParsed {processCommandLine(argc, argv, helpRequested, versionRequested, inputFile, outputFile)};

  if(!commandLineParsed) {
    return 1;
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
        << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
        << "  -h|--help        Print this help message and exit\n\n"
        << "  --version        Print version information\n\n"
        << "  -i FILE          Read text to be processed from FILE\n"
        << "                   Stdin will be used if not supplied\n\n"
        << "  -o FILE          Write processed text to FILE\n"
        << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested. Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFile.empty()) {
    std::cout << "[warning] input from file ('"
              << inputFile
              << "') not implemented yet, using stdin\n";
  }

  // Loop over stdin until Return then CTRL-D pressed (EOF)
  char inputChar {'x'};
  std::string inputText {""};

  while (std::cin >> inputChar) {
    inputText += transformChar(inputChar);
  }

  // Output the input text
  // Warn that output file option not yet implemented
  if (!outputFile.empty()) {
    std::cout << "[warning] output to file ('"
              << outputFile
              << "') not implemented yet, using stdout\n";
  }

  std::cout << inputText << "\n";

  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
  return 0;
}


