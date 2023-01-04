#pragma once

#include <string>

namespace cmdplus {
  /** \brief
   *  Class Version contains the major, minor, patch and build level of the application.
   */
  class Version {
  public:
    Version(int major, int minor, int patch, int build = 0) : _major(major), _minor(minor), _patch(patch), _build(build) {}
    Version(const Version& source) : _major(source._major), _minor(source._minor), _patch(source._patch), _build(source._build) {}
    Version(Version&& source) : _major(source._major), _minor(source._minor), _patch(source._patch), _build(source._build) {}
    ~Version() = default;

    Version& operator=(const Version&) = delete;
    Version& operator=(Version&&) = delete;

    const std::string format() const noexcept;

    const int getMajor() const noexcept { return _major; }
    const int getMinor() const noexcept { return _minor;}
    const int getPatch() const noexcept { return _patch; }
    const int getBuild() const noexcept { return _build; }

  private:

    int _major = 0;
    int _minor = 0;
    int _patch = 0;
    int _build = 0;
  };
}
