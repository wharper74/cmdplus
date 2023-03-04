#include "version.h"
#include "element.h"

#pragma once

namespace cmdplus {
  class Program {
  public:
    Program(const std::string& sw_name, const std::string& author, const Version& app_version ) noexcept : _software(sw_name), _author(author), _version(app_version) {}
    ~Program() = default;

    const std::string& getSoftwareName() const noexcept {return _software;}
    const std::string& getAuthor() const noexcept {return _author;}
    const Version& getVersion() const noexcept {return _version;}

  private:
    std::string _software;
    std::string _author;
    Version _version;
  };
}
