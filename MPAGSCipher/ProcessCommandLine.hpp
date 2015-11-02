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

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

