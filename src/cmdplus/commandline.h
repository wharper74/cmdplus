#include "version.h"

namespace cmdplus {
  class CommandLine {
  public:
    CommandLine(const std::string& app_name, const std::string& author, const Version& app_version ) noexcept : _application(app_name), _author(author), _version(app_version) {}
    ~CommandLine() = default;

    const std::string& getApplication() const noexcept {return _application;}
    const std::string& getAuthor() const noexcept {return _author;}
    const Version& getVersion() const noexcept {return _version;}

  private:
    std::string _application;
    std::string _author;
    Version _version;
  };
}
