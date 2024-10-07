#include <SWI-cpp.h>
#include <string>
#include <iostream>


PREDICATE(hello, 1)
{ std::cout << "Hello " << (char *)A1 << std::endl;

  return TRUE;
}
// int main(int argc, char **argv) {
    // return 1;
// }
