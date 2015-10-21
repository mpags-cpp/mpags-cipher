# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers


# Source Code Layout
Under this directory, the code and associated files are organised as
follows:

```sh
MPAGSCipher
├── README.md             This file, describes the project
├── LICENSE               License file, in our case MIT
├── CMakeLists.txt        CMake build script
├── mpags-cipher.cpp      Main program C++ source file
├── MPAGSCipher           Subdirectory for MPAGSCipher library code
|   └── CMakeLists.txt    Build sub-script for the MPAGSCipher library
├── Documentation         Subdirectory for documentation "code"
|   └── CMakeLists.txt    Build sub-script Doxygen HTML docs
|   └── Doxyfile.in       Doxygen configuration template
└── Testing               Subdirectory for code that tests MPAGSCipher
    └── CMakeLists.txt    Build sub-script for testing programs
    └── catch.hpp         C++ Header for the Catch testing framework
```

