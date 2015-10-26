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
    std::cout << "argv[" << i << "] = " << argvString << "\n";
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
