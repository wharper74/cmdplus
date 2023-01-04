#include <sstream>
#include "version.h"

using namespace cmdplus;

const std::string Version::format() const noexcept {
  std::ostringstream out ;

  out << this->getMajor() << "." << this->getMinor() << "." << this->getPatch() << "-" << this->getBuild();

  return out.str();
}
