/* Checks basic functionality of stat() system call. */

#include <random.h>
#include <stdio.h>
#include <syscall.h>
#include "tests/lib.h"
#include "tests/main.h"

void test_main (void)
{
  const unsigned int BUF_SIZE = 16;
  const char FILE_NAME[] = "yoit";
  int fd;
  int ret;
  char buf[BUF_SIZE];

  int exp_log_size = 512;
  int exp_phys_size = 0;
  int exp_blocks = 0;

  // Create file and check file status
  CHECK (create (FILE_NAME, exp_log_size), "create \"%s\"", FILE_NAME);
  CHECK ((fd = open (FILE_NAME)) > 1, "open \"%s\"", FILE_NAME);
  CHECK ((ret = stat (FILE_NAME, buf)) == 0,
         "return 0 from stat() call on \"%s\"", FILE_NAME);

  int logical_size = *((int *) buf);
  int physical_size = *((int *) buf + 1);
  int inode_number = *((int *) buf + 2);
  int blocks = *((int *) buf + 3);

  msg ("should have %d logical size: actual %d", exp_log_size, logical_size);
  msg ("should have %d physical size: actual %d", exp_phys_size, physical_size);
  CHECK (inode_number > 0, "valid inode number");
  msg ("should have %d block: actual %d", exp_blocks, blocks);
}