#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
  int priority1, priority2;

  if (argc < 1) {
      printf(2, "Usage: myprogram [priority1] [priority2]\n" );
      exit();
  }
  priority1 = atoi(argv[1]);
  priority2 = atoi(argv[2]);

  if (priority1 < 1 || priority1 > 100 || priority2 < 1 || priority2 > 100) 
  {
      printf(1, "Invalid priority (1-100)!\n" );
      exit();
  }

  int pid1;
	pid1 = fork();
  if(pid1 < 0)
  {
    printf(1, "fork failed\n");
    exit();
  }
	else if (pid1 == 0)
  {	
      int old1 = setpriority(priority1);
      printf(2,"in child 1 with old priority :%d\n", old1);
      for(int i=0; i<1000; i++)
          if(i%3 == 0 && i%7 == 0 && i%5 == 0)
            printf(1, "CHILD\n");
      exit();
  }
  else
 	{
      // // setpriority(55);
    	// int pid2 = fork();
      // if(pid2 < 0)
      // {
      //   printf(1, "fork failed\n");
      //   exit();
      // }
      // else if(pid2 == 0)
      // {
      //   setpriority(priority2);
      //   printf(1,"in child2\n");
      //   for(int i=0; i<1000; i++)
      //     if(i%3 == 0 && i%7 == 0 && i%5 == 0)
      //       printf(1, "booooo"\n");
        
      //   exit();
      // }
      // else
      // {
      //   // setpriority(90);
      //   printf(1,"in parent2\n");
      //   int wait2 = wait();
      //   if(wait2 < 0)
      //   {
      //     printf(1, "wait stopped early\n");
      //     exit();
      //   }
      //   // exit();
      // }
      
      int old2 = setpriority(priority2);
      printf(2,"in parent 1 with old priority :%d\n",old2);
      for(int i=0; i<1000; i++)
          if(i%3 == 0 && i%7 == 0 && i%5 == 0)
            printf(1, "PARENT\n");
      
      int wait1 = wait();
      if(wait1 < 0)
      {
        printf(1, "wait stopped early\n");
        exit();
      }
 	}  

  
  printf(1, "ghable exit e akhar\n");
  exit();
}
