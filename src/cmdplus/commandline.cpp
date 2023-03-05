#include "commandline.h"
#include <stdexcept>

using namespace cmdplus;


CommandLine::CommandLine(int argc, const char* args[]) noexcept {
  if (argc > 0 && args != 0) {
    _args.reserve(argc);
    for (int i = 0; i < argc; i++) {
      _args.push_back(string(args[i]));
    }
  }
}


const string& CommandLine::at(size_t pos) const {
  if (pos >= 0 && pos < _args.size()) {
    return _args[pos];
  }
  else {
    throw out_of_range("No parameter at the specified index.");
  }
}
