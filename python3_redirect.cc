#include <unistd.h>
#include <array>
#include <cstdio>
#include <iostream>
#include <memory>
#include <regex>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  std::string check_cmd = "C:\\Anaconda3\\pipe_check";

  std::string py_cmd = "C:\\Anaconda3\\python ";
  std::string args;
  for (int i = 1; i < argc; i++) {
    args += "\"" + std::string(argv[i]) + "\" ";
  }
  args = std::regex_replace(args, std::regex("\n"), "");

  std::array<char, 128> buffer;
  std::string result;
  bool is_pipe = !system(check_cmd.c_str());

  if (is_pipe) {
    // std::cerr << "pipe" << std::endl;
    std::string cmd = py_cmd + " " + args;
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
      if (fgets(buffer.data(), 128, pipe.get()) != NULL)
        result += buffer.data();
    }
    std::cout << result;
  } else {
    // std::cerr << "terminal" << std::endl;
    std::string cmd = std::string("winpty ") + py_cmd + args;
    system(cmd.c_str());
  }

  return EXIT_SUCCESS;
}