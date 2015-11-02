#include "CaesarCipher.hpp"

#include <cctype>
#include <string>
#include <vector>

bool CaesarCipher(const std::string& input, const std::string& key,
                  const bool decrypt, std::string& output) {

  const std::vector<char> plainAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize {plainAlphabet.size()};

  // Check that the key string if of non-zero length
  if ( key.empty() ) {
    return false;
  }
  // If so, also check that all characters in the key string are digits
  for (const char c : key) {
    if ( ! std::isdigit(c) ) {
      return false;
    }
  }

  // Convert the string to an unsigned integer to get the shift
  const size_t caesarShift {std::stoul(key) % alphabetSize};

  // Store encrypted char
  char processedChar {'x'};

  // Range based for input...
  for (const char c : input) {
    // Indexed for search (neatest way to enumerate iteration)
    for (size_t i{0}; i< alphabetSize; ++i) {
      if (c == plainAlphabet[i]) {
        if (decrypt) {
          processedChar = plainAlphabet[ (i + alphabetSize - caesarShift) % alphabetSize ];
        }
        else {
            processedChar = plainAlphabet[ (i + caesarShift) % alphabetSize ];
        }
      }
    }
    output.push_back(processedChar);
  }

  return true;
}

