#include "tests/lib.h"
#include "tests/main.h"
#include <syscall.h>

void test_main (void)
{
  char *file_name = "sparse-file";
  CHECK (create (file_name, 0), "create \"%s\"", file_name);
  CHECK (int fd = open (file_name), "open \"%s\"", file_name);
  CHECK (test_sparse_files (fd), "check sparse file allocation");
}
