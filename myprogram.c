#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

// int main (int argc,char *argv[])
// {

// 	int status = 20, wait_time, run_time;	
//   int pid1;
// 	pid1 = fork();
//   if(pid1 < 0)
//   {
//     printf(1, "fork failed\n");
//     exit();
//   }
// 	else if (pid1 == 0)
//   {	
//       nice();
//       printf(1,"in child1\n");
//       for(int i=0; i<1000; i++)
//           if(i%3 == 0 && i%7 == 0 && i%5 == 0)
//             printf(1, "GAV\n");
//   }
//   else
//  	{
//       // setpriority(55);
//     	int pid2 = fork();
//       if(pid2 < 0)
//       {
//         printf(1, "fork failed\n");
//         exit();
//       }
//       else if(pid2 == 0)
//       {
//         // setpriority(priority2);
//         printf(1,"in child2\n");
//         for(int i=0; i<1000; i++)
//           if(i%3 == 0 && i%7 == 0 && i%5 == 0)
//             printf(1, "KHAR\n");
        
//         // exit();
//       }
//       else
//       {
//         // setpriority(90);
//         printf(1,"in parent2\n");
//         status = waitx(&wait_time, &run_time);
//         printf(1, "Wait Time = %d\t Run Time = %d with Status %d \n", wait_time, run_time, status); 
//         exit();
//       }
      
//       printf(1,"in parent1\n");
//       status = waitx(&wait_time, &run_time);
//         printf(1, "Wait Time = %d\t Run Time = %d with Status %d \n", wait_time, run_time, status); 
//       // exit();
//  	}  

  
//   printf(1, "ghable exit e akhar\n");
//   exit();
// }

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
      nice();
      status = waitx(&wait_time, &run_time);
 	}  
 	printf(1, "Wait Time = %d\t Run Time = %d with Status %d \n", wait_time, run_time, status); 
 	exit();
}

