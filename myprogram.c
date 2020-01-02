#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int priority;

  if (argc < 2) {
      printf(2, "Usage: myprogram [priority]\n" );
      exit();
  }
  priority = atoi(argv[1]);

  printf(2, "you entered %d\n", priority );

  if (priority < 1 || priority > 100) {
      printf(2, "Invalid priority (1-100)!\n" );
      exit();
  }

  setpriority(priority);

  exit();
}
