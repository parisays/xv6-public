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
    struct proc_info* mylist = malloc(NPROC * sizeof(struct proc_info));
    int rc = fork();
    if (rc < 0) {

        // fork failed; exit
        printf(1,"first fork failed\n");
        exit();
        
    } else if (rc == 0) {

        pinfo(&mylist);
        exit();

    } else {

        // parent goes down this path (original process)        
        int count = 0;
        for(int i=0; i<10000 ;i++)
            for(int j=0; j<10000; j++)
                for(int k=0; k<10000; k++)
                    count++;
        wait();
        exit();
    }

    exit();
}