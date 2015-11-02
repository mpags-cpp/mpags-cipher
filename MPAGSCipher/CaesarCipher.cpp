#include "CaesarCipher.hpp"

#include <string>
#include <vector>

bool CaesarCipher(const std::string& input, const std::string& key,
                  const bool decrypt, std::string& output) {

  std::vector<char> plainAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  size_t alphabetSize {plainAlphabet.size()};

  // NB, this doesn't handle all error cases - i.e. the supplied string
  // is *not* convertible. Appropriate method is exceptions
  size_t caesarShift {std::stoul(key) % alphabetSize};

  // Store encrypted char
  char processedChar {'x'};

  // Range based for input...
  for (char c : input) {
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

