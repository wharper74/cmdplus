#include "version.h"
#include "element.h"
#include "commandline.h"

#pragma once

namespace cmdplus {
  class Program {
  public:
    using ProgramInfo = struct _program_info {

      _program_info() = delete;
      _program_info(const string& sw, const string& auth) : _author(auth), _software(sw) {}

      string _software;
      string _author;
    };

  public:
    Program(const ProgramInfo& pi, const Version& app_version, int argc, const char* args[]) noexcept : _info(pi), _version(app_version), _command_line(argc, args) {}
    ~Program() = default;

    const std::string& getAuthor() const noexcept {return _info._author;}
    const CommandLine& getCommandLine() const { return _command_line; }
    const std::string& getSoftwareName() const noexcept { return _info._software; }
    const Version& getVersion() const noexcept {return _version;}

  private:
    ProgramInfo _info;
    Version _version;
    CommandLine _command_line;
    
  };
}
