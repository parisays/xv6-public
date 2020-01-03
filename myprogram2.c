#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[])
{
  int status = 20, wait_time, run_time;	

  int pid1;
	pid1 = fork();
  if(pid1 < 0)
  {
    printf(1, "fork failed\n");
    exit();
  }
	else if (pid1 == 0)
  {	
      nice();
      for(int i=0; i<1000; i++)
          if(i%3 == 0 && i%7 == 0 && i%5 == 0)
            printf(1, "CHILD\n");
      exit();
  }
  else
 	{
    //   nice();
      // sleep(10);
      for(int i=0; i<1000; i++)
          if(i%3 == 0 && i%7 == 0 && i%5 == 0)
            printf(1, "PARENT\n");
      
      status = waitx(&wait_time, &run_time);
      
 	}  

  
  printf(1, "Wait Time = %d\t Run Time = %d with Status %d \n", wait_time, run_time, status); 
  exit();
}

