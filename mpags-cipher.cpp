// Standard Library includes
#include <iostream>
#include <string>

// For std::isalpha and std::isupper
#include <cctype>

//! Main function of the mpags-cipher program
int main(int /*argc*/, char* /*argv*/[]) {
  // Read in user input from stdin
  char inputChar {'x'};
  std::string inputText {""};

  // Loop over stdin until Return then CTRL-D pressed (EOF)
  while (std::cin >> inputChar) {
    // Uppercase alphabetic characters
    if (std::isalpha(inputChar)) {
      inputText += std::toupper(inputChar);
    }

    // Discard everything else
  }

  // Output the input text
  std::cout << inputText << "\n";

  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
  return 0;
}
