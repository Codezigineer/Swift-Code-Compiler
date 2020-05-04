#include <iostream>
#include <string>
#include "compile.h" // We Use compiling stuff.

int main() 
{
  std::cout << "Hello!\n";
  std::cout << "Welcome To the Swift Code Compiler!\n";
  std::cout << "Enter run, then hit enter to run.\n";

  // Variable for code.
  std::string code = "";

  // Tells the user to enter code.
  std::cout << "Enter your code:\n";

  // Entry for code.
  while(true)
    std::cin >> code;

  if (code == "run")
    std::cout << "hey, enter your code first!\n";
    exit(0);

  // Help me with this! :)
  if (code == std::string() + "\nrun")
    // Do something to check the code before the user entered "run". Why there is nothing here is because i am working. :)
    exit(0);
}