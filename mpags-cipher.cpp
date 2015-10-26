// Standard Library includes
#include <iostream>
#include <string>

//! Main function of the mpags-cipher program
int main(int /*argc*/, char* /*argv*/[]) {
  // Integer variable
  int answer {1};
  answer = 42;
  std::cout << "The answer is " << answer << "\n";

  // double with const
  const double pi {3.14};
  std::cout << "PI is " << pi << " to 2dp\n";

  // Product...
  std::cout << "answer * pi = " << answer*pi << "\n";

  // Division
  std::cout << "pi / answer = " << pi / answer << "\n";

  int rewsna {24};
  std::cout << "answer / rewsna = " << answer / rewsna << "\n";

  // Hello world for C++ using strings
  std::string msg {"Hello World!"};
  std::cout << msg << "\n";

  auto singleChar = msg[4];
  std::cout << "5th char of message = " << singleChar << "\n";


  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
  return 0;
}
