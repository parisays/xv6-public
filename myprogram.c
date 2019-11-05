#include "types.h"
#include "stat.h"
#include "user.h"

#define NPROC 64

struct proc_info {
  int pid;
  int memsize;
};

int
main(void)
{
    int rc = fork();
    if (rc < 0) {

        // fork failed; exit
        printf(1,"first fork failed\n");
        exit();
        
    } else if (rc == 0) {

        // child (new process)
        
        int count = 0;
        for(int i=0; i<1000 ;i++)
            for(int j=0; j<1000; j++)
                for(int k=0; k<1000; k++)
                    count++;
        exit();

    } else {

        // parent goes down this path (original process)

        wait();
        struct proc_info* mylist = malloc(NPROC * sizeof(struct proc_info));
        int result = pinfo((void*)mylist);
        printf(1, "result : %d \n", result);
        exit();
    }

    exit();
}