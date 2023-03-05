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

TEST_CASE("Program class") {
  const char* args[] = { "this", "is", "a", "command", "line" };
  int argc = 5;
  Program program(Program::ProgramInfo( "MyTest", "Davide Gioia"), Version(1, 2, 3, 8832), argc, args);

  CHECK(program.getVersion().format() == "1.2.3-8832");
  CHECK(program.getAuthor() == "Davide Gioia");
  CHECK(program.getSoftwareName() == "MyTest");   
  
  CHECK(program.getCommandLine().size() == 5);
  CHECK(program.getCommandLine().at(0) == args[0]);
  CHECK(program.getCommandLine().at(argc-1) == args[argc - 1]);
  CHECK_THROWS_AS(program.getCommandLine().at(argc + 1),std::out_of_range);
}
