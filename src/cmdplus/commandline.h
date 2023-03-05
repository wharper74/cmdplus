#pragma once

#include <vector>
#include <string>


namespace cmdplus {

  using namespace std;

  class CommandLine {
  public:
    CommandLine(int argc, const char* args[]) noexcept;

    size_t size() const noexcept { return _args.size(); }

    const string& at(size_t pos) const;

  private:
    vector<string> _args;
  };

}