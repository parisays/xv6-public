#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc,char *argv[])
{

	int pid;
	int status = 20, a, b;	
	pid = fork();
	if (pid == 0)
  	{	
  		// exec(argv[1], argv);
    	// printf(1, "exec %s failed\n", argv[1]);
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
    	status = waitx(&a, &b);
 	}  
 	printf(1, "Wait Time = %d\n Run Time = %d with Status %d \n", a, b, status); 
 	exit();
}