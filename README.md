# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

# Building `mpags-cipher`
Compilation of `mpags-cipher` requires the [CMake](http://www.cmake.org)
build tool, plus a  C++11 compatible compiler (GCC 4.8 or better, Clang
3.4 or better are recommended) and `make` on a UNIX operating system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, open a terminal window
and change directory into that holding this README. Create a build
directory in which to run `cmake` and the build, and change into it:

```
$ ls
CMakeLists.txt   LICENSE          README.md        mpags-cipher.cpp
Documentation    MPAGSCipher      Testing
$ mkdir Build
$ cd Build
```

Run `cmake` in this directory, pointing it to the directory holding this
README, and consequently the top level CMake sxript for the project:

```
$ cmake ..
... system specific output ...
-- Configuring done
-- Generating done
-- Build files have been written to: ... your build dir path ...
$
```

The exact output will depend on your system, compiler and build directory
location, but you should not see any errors. CMake will generate
Makefiles by default on UNIX platforms, so to build, simply run `make`
in the build directory:

```
$ ls
CMakeCache.txt      CMakeFiles          Makefile            cmake_install.cmake
$ make
... verbose output ...
[100%] Built target mpags-cipher
...
$
```

Again, the exact output will be system specific, but you should see the
`mpags-cipher` target built without error. The resulting `mpags-cipher`
executable can then be run directly, and provides the following command
line options:

```
$ ./mpags-cipher --help
Usage: mpags-cipher [-i <file>] [-k <KEY>] [-o <file>]

Encrypts/Decrypts input alphanumeric text using classical ciphers

Available options:

  -h|--help        Print this help message and exit

  --version        Print version information

  -i FILE          Read text to be processed from FILE
                   Stdin will be used if not supplied

  -o FILE          Write processed text to FILE
                   Stdout will be used if not supplied

  -k KEY           Use KEY as key for cipher
                   A null key, i.e. no encryption, is used if not supplied

  --decrypt        Decrypt input text using KEY instead of
                   encrypting

```

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.
It will then echo the input to stdout or write it to the file supplied with
the `-o` option.

To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

At present only the Caesar Cipher is supported.

# Installing `mpags-cipher`
After building `mpags-cipher`, it may be installed by building the
`install` target, e.g.

```
$ make install
```

The default installation location will be system dependent (usually
`/usr/local` on UNIX systems), and may be adjusted by the CMake variables

- `CMAKE_INSTALL_PREFIX` to set the installation prefix
- `CMAKE_INSTALL_BINDIR` to set the directory under `CMAKE_INSTALL_PREFIX` where programs should be installed.

Both variables may be supplied as command line definitions (`-D` flags)
to CMake, e.g.

```
$ cmake -DCMAKE_INSTALL_PREFIX=/other/path ...
```

or can be editted in the CMake cache via `ccmake`.

# Packaging `mpags-cipher`
In addition to installing, `mpags-cipher` sources and binaries may be
packaged for distribution. To build a source package, build the `package_source` target, e.g.:

```
$ make package_source
```

This will create compressed tar archives of the source code in its current
state (to package a specific version you should checkout the tag/commit for
that version first).

To build a binary package, build the `package` target, e.g.:

```
$ make package
```

This will create compressed tar archives and a self-extracting tar
installer for the `mpags-cipher` program.

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

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.

