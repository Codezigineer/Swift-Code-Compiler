// we do not just have main.cpp.
#ifndef COMPILE_H

// including in headers.
#include <iostream>
#include <string>

// of Course We add header gaurds.
#define COMPILE_H

namespace compile // namespace for compiling.
{

  // For checking syntax.
  int check_syntax(std::string code)
  {
    // We are gonna work on this.
    // We return an integer so that we know if the code is right.
    // codes for returning:
    //    1 - There is an error in syntax.
    //    0 - There is no bad syntax.

    // We return 0 because we are working on the function said on line 17.
    return 0;
  }

  // For compiling the code.
  void compile_code(std::string code)
  {
    // We check if there is an error: go to the function compile::check_syntax(). The variable codehaserror stores the value if there is an error in syntax.
    int codehaserror = compile::check_syntax(code);

    if (codehaserror == 1)
      std::cout << "Ran Failed.";
    if (codehaserror == 0)
      // Tell the user if the program is running.
      std::cout << "Running..."; 
      std::cout << "Ran Succeded.";

    // Working on this.

    // Tell the user if the program is ran. The Function compile::check_syntax() will say any syntax errors.
  }
}

#endif