//! \file ProcessCommandLine.hpp
#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

//! Extract configuration information from command line arguments
/*!
  \return True if command line parsing suceeded
*/
bool processCommandLine(const int argc, char* argv[],
                        bool& requiresHelp,
                        bool& requiresVersion,
                        std::string& inputFile,
                        std::string& outputFile,
                        std::string& cipherKey,
                        bool& cipherDecrypt);

//! Print help on command line interface to stdout
void doPrintCommandLineHelp();

//! Print version of mpags-cipher to stdout
void doPrintCommandLineVersion();

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

