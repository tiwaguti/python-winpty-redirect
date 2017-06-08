#include <unistd.h>
#include <cstdio>
#include <iostream>

int main(int argc, char* argv[]) {
  // std::cerr << isatty(fileno(stdout)) << std::endl;
  exit(isatty(fileno(stdout)));
}