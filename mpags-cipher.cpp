// Standard Library includes
#include <iostream>
#include <string>

// For std::isalpha and std::isupper
#include <cctype>

//! Main function of the mpags-cipher program
int main(int argc, char* argv[]) {
  // Process command line arguments
  for (int i {0}; i < argc; ++i) {
    std::string argvString(argv[i]);

    // Check for help request
    if (argvString == "-h" || argvString == "--help") {
      // Line splitting for readability
      std::cout
        << "Usage: mpags-cipher \n\n"
        << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
        << "Available options:\n\n"
        << "  -h|--help        Print this help message and exit\n\n";
      // Help requires no further action, so return from main
      // with 0 used to indicate success
      return 0;
    }
  }

  // Read in user input from stdin
  char inputChar {'x'};
  std::string inputText {""};

  // Loop over stdin until Return then CTRL-D pressed (EOF)
  while (std::cin >> inputChar) {
    // Uppercase alphabetic characters
    if (std::isalpha(inputChar)) {
      inputText += std::toupper(inputChar);
    }

    // Transliterate digits to English words
    switch (inputChar) {
      case '0':
        inputText += "ZERO";
        break;
      case '1':
        inputText += "ONE";
        break;
      case '2':
        inputText += "TWO";
        break;
      case '3':
        inputText += "THREE";
        break;
      case '4':
        inputText += "FOUR";
        break;
      case '5':
        inputText += "FIVE";
        break;
      case '6':
        inputText += "SIX";
        break;
      case '7':
        inputText += "SEVEN";
        break;
      case '8':
        inputText += "EIGHT";
        break;
      case '9':
        inputText += "NINE";
        break;
    }

    // Discard everything else as our ciphers cannot work with them
  }

  // Output the input text
  std::cout << inputText << "\n";

  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
  return 0;
}
