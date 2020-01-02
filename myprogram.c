#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{

	int pid;
	int status = 20, wait_time, run_time;	
	pid = fork();
	if (pid == 0)
  {	
      //argv array for: ls -l
      char * ls_args[] = { "ls" , "-l", "\0"};
      //  use the name ls
      //  rather than the
      //  path to /bin/ls
      exec(ls_args[0],ls_args);

      //only get here on error
      printf(1, "exec %s failed\n", ls_args[0]);
  }
  else
 	{
    	status = waitx(&wait_time, &run_time);
 	}  
 	printf(1, "Wait Time = %d\t Run Time = %d with Status %d \n", wait_time, run_time, status); 
 	exit();
}