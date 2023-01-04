#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../cmdplus/cmdplus.h"

using namespace cmdplus;

TEST_SUITE("Command Plus" * doctest::description("Command Plus Test Cases")) {
  TEST_CASE("Testing version and author attributes") {
    Version v(1,2,3,8832);
    CommandLine cl("MyTest", "John Smith", v );

    CHECK(cl.getVersion().format() == "1.2.3-8832");
    CHECK(cl.getAuthor() == "John Smith");
    CHECK(cl.getApplication() == "MyTest");
  }
}
