//! \file CaesarCipher.hpp
#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>

//! Process input text to output text with Caesar Cipher
/*!
 \param input String to be processed
 \param key   Key to be used for processing
 \param decrypt Boolean flag set to true if decryption is to be applied
 \param output  String reference to fill with processed text
 \return boolean indicating successful processing
*/
bool CaesarCipher(const std::string& input, const std::string& key,
                  const bool decrypt, std::string& output);

#endif // MPAGSCIPHER_CAESARCIPHER_HPP

