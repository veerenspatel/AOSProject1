#include "tests/lib/tests.h"
#include "threads/thread.h"
#include "threads/malloc.h"
#include "lib/kernel/list.h"
#include <debug.h>
#include <string.h>
#include <stdio.h>

struct test
{
  const char *name;
  test_func *function;
};

static const struct test tests[] = {
    {"sorted-thread-list", sorted_thread_list},
    {"unsorted-thread-list", unsorted_thread_list},
    {"bad-input", bad_input},
    {"not-found", not_found}
};

void sorted_thread_list() {
  struct list threads;
  list_init(&threads);

  struct thread *target = NULL;
  for (int i = 0; i < 10; i++) {
    struct thread *thread = (struct thread *) malloc(sizeof(struct thread));
    thread->tid = i;
    list_push_back(&threads, &thread->allelem);
    if (i == 4) target = thread;
  }

  int index = get_sorted_index(&threads, target);
  msg("sorted index %d", index);
}

void unsorted_thread_list() {
  struct list threads;
  list_init(&threads);

  struct thread *thread0 = (struct thread *) malloc(sizeof(struct thread));
  thread0->tid = 7;
  list_push_back(&threads, &thread0->allelem);
  struct thread *thread1 = (struct thread *) malloc(sizeof(struct thread));
  thread1->tid = 0;
  list_push_back(&threads, &thread1->allelem);
  struct thread *thread2 = (struct thread *) malloc(sizeof(struct thread));
  thread2->tid = 5;
  list_push_back(&threads, &thread2->allelem);
  struct thread *thread3 = (struct thread *) malloc(sizeof(struct thread));
  thread3->tid = 3;
  list_push_back(&threads, &thread3->allelem);
  struct thread *thread4 = (struct thread *) malloc(sizeof(struct thread));
  thread4->tid = 8;
  list_push_back(&threads, &thread4->allelem);
  struct thread *thread5 = (struct thread *) malloc(sizeof(struct thread));
  thread5->tid = 2;
  list_push_back(&threads, &thread5->allelem);
  struct thread *thread6 = (struct thread *) malloc(sizeof(struct thread));
  thread6->tid = 1;
  list_push_back(&threads, &thread6->allelem);
  struct thread *thread7 = (struct thread *) malloc(sizeof(struct thread));
  thread7->tid = 4;
  list_push_back(&threads, &thread7->allelem);
  struct thread *thread8 = (struct thread *) malloc(sizeof(struct thread));
  thread8->tid = 6;
  list_push_back(&threads, &thread8->allelem);
  struct thread *thread9 = (struct thread *) malloc(sizeof(struct thread));
  thread9->tid = 9;
  list_push_back(&threads, &thread9->allelem);

  int index = get_sorted_index(&threads, thread8);
  msg("sorted index %d", index);
}

void bad_input() {
  int index = get_sorted_index(NULL, NULL);
  msg("sorted index %d", index);
}

void not_found() {
  struct list threads;
  list_init(&threads);

  struct thread *target = (struct thread *) malloc(sizeof(struct thread));
  for (int i = 0; i < 10; i++) {
    struct thread *thread = (struct thread *) malloc(sizeof(struct thread));
    thread->tid = i;
    list_push_back(&threads, &thread->allelem);
  }

  int index = get_sorted_index(&threads, target);
  msg("sorted index %d", index);
}

static const char *test_name;

/* Runs the test named NAME. */
void run_test (const char *name)
{
  const struct test *t;

  for (t = tests; t < tests + sizeof tests / sizeof *tests; t++)
    if (!strcmp (name, t->name))
      {
        test_name = name;
        msg ("begin");
        t->function ();
        msg ("end");
        return;
      }
  PANIC ("no test named \"%s\"", name);
}

/* Prints FORMAT as if with printf(),
   prefixing the output by the name of the test
   and following it with a new-line character. */
void msg (const char *format, ...)
{
  va_list args;

  printf ("(%s) ", test_name);
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
  putchar ('\n');
}

/* Prints failure message FORMAT as if with printf(),
   prefixing the output by the name of the test and FAIL:
   and following it with a new-line character,
   and then panics the kernel. */
void fail (const char *format, ...)
{
  va_list args;

  printf ("(%s) FAIL: ", test_name);
  va_start (args, format);
  vprintf (format, args);
  va_end (args);
  putchar ('\n');

  PANIC ("test failed");
}

/* Prints a message indicating the current test passed. */
void pass (void) { printf ("(%s) PASS\n", test_name); }