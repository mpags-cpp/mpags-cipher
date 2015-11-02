#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

//!
/*
  !param
  !return True if command line parsing suceeded
*/
bool processCommandLine(int argc, char* argv[],
                        bool& requiresHelp,
                        bool& requiresVersion,
                        std::string& inputFile,
                        std::string& outputFile);

//! Print help on command line interface to stdout
void doPrintCommandLineHelp();

//! Print version of mpags-cipher to stdout
void doPrintCommandLineVersion();

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

