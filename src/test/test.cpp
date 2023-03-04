#include <iostream>
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "../cmdplus/cmdplus.h"

using namespace std;
using namespace cmdplus;

enum option_id {
  ID_HELP = 1,
  ID_RECURSIVE = 2
};

TEST_SUITE("Functional" * doctest::description("Functional Tests for CommandPlus")) {
  Program program("MyTest", "Davide Gioia", Version(1, 2, 3, 8832));

  TEST_CASE("Program class") {

    CHECK(program.getVersion().format() == "1.2.3-8832");
    CHECK(program.getAuthor() == "Davide Gioia");
    CHECK(program.getSoftwareName() == "MyTest");
  }
}
