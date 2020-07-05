#include "types.h"
#include "user.h"


int
main(int argc, char *argv[])
{
	if (argc != 2){
				printf(1, "Usage: sanity <n>\n");
				exit();
 		}
	int i;
	int n;
	int j = 0;
	int k;
	int wtime;
	int rtime;
	int sums[3][2];
	for (i = 0; i < 3; i++)
		for (j = 0; j < 2; j++)
			sums[i][j] = 0;
	n = atoi(argv[1]);
	int pid;
	for (i = 0; i < n; i++) 
    {
		j = i % 3;
		pid = fork();
		if (pid == 0) 
        {//child
			j = (getpid() - 4) % 3; // ensures independence from the first son's pid when gathering the results in the second part of the program
			switch(j) {
				case 0:
                    setpq(0, 30); // set to priority
					break;
				case 1:
                    setpq(1, 80); // set to FCFS
					break;
				case 2:
                    nice(); // redue to RR
					break;
			}
            for (k = 0; k < 100; k++)
            {
                for (double z = 0; z < 1000.0; z+= 0.1)
                {
                    double x =  x + 3.14 * 89.64;   // useless calculations to consume CPU time
                }
            }
			exit(); // children exit here
		}
		continue; // father continues to spawn the next child
	}
	for (i = 0; i < n; i++) 
    {
		pid = waitx(&wtime, &rtime);
		int res = (pid - 4) % 3; // correlates to j in the dispatching loop
		switch(res) 
        {
			case 0: // CPU bound processes
				printf(1, "Queue 0, pid: %d, wait time: %d, run time: %d\n", pid, wtime, rtime);
				sums[0][0] += wtime;
				sums[0][1] += rtime;
				break;
			case 1: // CPU bound processes, short tasks
				printf(1, "Queue 1, pid: %d, wait time: %d, run time: %d\n", pid, wtime, rtime);
				sums[1][0] += wtime;
				sums[1][1] += rtime;
				break;
			case 2: // simulating I/O bound processes
				printf(1, "Queue 2, pid: %d, wait time: %d, run time: %d\n", pid, wtime, rtime);
				sums[2][0] += wtime;
				sums[2][1] += rtime;
				break;
		}
	}
	
    printf(1, "*************RESULTS**************\n");

    for (i = 0; i < 3; i++)
    {
        printf(1, "Queue %d:\nTotal wait time: %d | Average wait time: %d\nTotal running time: %d | Average running time: %d\n",
            i, sums[i][0], sums[i][0]/n, sums[i][1], sums[i][1]/n);
    }
    
	exit();
}
