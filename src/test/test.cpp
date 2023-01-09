#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../cmdplus/cmdplus.h"

using namespace cmdplus;

enum option_id {
  ID_HELP = 1,
  ID_RECURSIVE = 2
};

TEST_SUITE("Command Plus" * doctest::description("Command Plus Test Cases")) {
  TEST_CASE("Primitives") {
    Version v(1,2,3,8832);
    CommandLine cl("MyTest", "John Smith", v );
    Element<int> e(1,"h","Help",false);

    CHECK(cl.getVersion().format() == "1.2.3-8832");
    CHECK(cl.getAuthor() == "John Smith");
    CHECK(cl.getApplication() == "MyTest");

    CHECK(e.isOptional() == false );
    CHECK(e.isMandatory() == true );
  }

  TEST_CASE("Testing options") {
    CommandLine clbool("Boolean tests", "Davide Gioia", Version(1,1,0));
    char* arguments[] = {
      (char*)"ciao",
      (char*)"aa"
    };

    //clbool.Add( BooleanOption(ID_HELP,"h","help","Shows the help for this command",false));

  }
}
