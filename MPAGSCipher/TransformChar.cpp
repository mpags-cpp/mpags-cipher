#include "TransformChar.hpp"

#include <string>
#include <cctype>

std::string transformChar(const char c) {
  std::string inputText {""};

  // Uppercase alphabetic characters
  if (std::isalpha(c)) {
    inputText += std::toupper(c);
  }

  // Transliterate digits to English words
  switch (c) {
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
  return inputText;
}

