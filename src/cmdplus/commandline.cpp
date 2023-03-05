#include "commandline.h"
#include <stdexcept>

using namespace cmdplus;

/*
* Builds a wrapper for the argc, argv main parameters
* 
*/
CommandLine::CommandLine(int argc, const char* args[]) noexcept {
  if (argc > 0 && args != 0) {
    _args.reserve(argc);
    for (int i = 0; i < argc; i++) {
      _args.push_back(string(args[i]));
    }
  }
}


/**
* Gets the parameter that occupies the specified position in the shell command line
* 
* @throws std::out_of_range when the "pos" index is outside the command line boundaries
*/
const string& CommandLine::at(size_t pos) const {
  if (pos >= 0 && pos < _args.size()) {
    return _args[pos];
  }
  else {
    throw out_of_range("No parameter at the specified index.");
  }
}
