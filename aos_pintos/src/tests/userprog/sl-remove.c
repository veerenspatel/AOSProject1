/* Create a symbolic link and then remove target file. */

#include <syscall.h>
#include "tests/userprog/sample.inc"
#include "tests/lib.h"
#include "tests/main.h"

void test_main (void)
{
  int target_fd;
  char *target = "test.txt";
  char *linkpath = "test-link.txt";

  CHECK (create ("test.txt", sizeof sample - 1), "create \"test.txt\"");
  CHECK ((target_fd = open ("test.txt")) > 1, "open \"test.txt\"");

  int result = symlink (target, linkpath);
  if (result != 0)
    fail ("symlink() returned %d instead of 0", result);
  else
    msg ("symlink() successfully returned 0");

  CHECK (remove (target), "remove \"test.txt\" file");
  CHECK (open ("test-link.txt") == -1, "open \"test-link.txt\" should fail");
}
