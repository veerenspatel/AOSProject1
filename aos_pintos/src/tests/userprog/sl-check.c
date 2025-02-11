/* Basic check that symbolic link created. */
#include <syscall.h>
#include "tests/userprog/sample.inc"
#include "tests/lib.h"
#include "tests/main.h"

void test_main (void)
{
  int handle;
  char *target = "test.txt";
  char *linkpath = "test-link.txt";

  CHECK (create ("test.txt", sizeof sample - 1), "create \"test.txt\"");
  CHECK ((handle = open ("test.txt")) > 1, "open \"test.txt\"");

  int result = symlink (target, linkpath);
  if (result != 0)
    {
      fail ("symlink() returned %d instead of 0", result);
    }
  else
    {
      msg ("symlink() successfully returned 0");
    }

  CHECK ((handle = open ("test-link.txt")) > 1, "open \"test-link.txt\"");
}
