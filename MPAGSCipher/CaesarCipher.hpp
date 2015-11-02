#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

//! Process input text to output text with Caesar Cipher
/*
 !param
 !return boolean indicating successful processing
*/
bool CaesarCipher(const std::string& input, const std::string& key,
                  const bool decrypt, std::string& output);

#endif // MPAGSCIPHER_CAESARCIPHER_HPP

