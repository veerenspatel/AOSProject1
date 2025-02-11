/* Try to create symbolic link to target that doesn't exist. */

#include <syscall.h>
#include <stdio.h>
#include "tests/userprog/sample.inc"
#include "tests/lib.h"
#include "tests/main.h"

void test_main (void)
{
  char *target = "test.txt";
  char *linkpath = "test-link.txt";

  int result = symlink (target, linkpath);
  msg ("passed in invalid target to symlink");
  if (result != -1)
    {
      fail ("symlink() returned %d instead of -1", result);
    }
  else
    {
      msg ("symlink() returned -1");
    }
}
