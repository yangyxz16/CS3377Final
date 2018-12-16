#include <stdio.h>
//#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
//#include <iostream>

void verbose();

int main(int argc, char **argv)
{
	int c;		// Used for getopt().
	int percent;
	int numOfT;	// Number of trails.
	bool verbose = false;
	char * fileName;

	while ((c = getopt(argc, argv, "p:vo:")) != -1) {
		switch(c) {
			case 'p': 
				//p = optarg;		
				percent = atoi(optarg);
				break;
			case 'v': 
				verbose = true;
				break;
			case 'o':
				fileName = optarg;
				break;
			default:
				fprintf(stderr, "getopt");
		}
	}


	numOfT = atoi(argv[optind]);

	if (percent > 100) {
		fprintf(stderr, "The percentage cannot be larger than 100!\n");
		exit(-1);
	}

	if (numOfT == 0) {
		fprintf(stderr, "The number of trails is invaild!\n");
		exit(-1);
	}

	printf("%s\n", fileName);

	int fd, sz;

	fd = open(fileName, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0) { perror("r1"); exit(1); }

	sz = write(fd, "cs3377\n", strlen("cs3377\n"));

	printf("called write(%d, \"cs3377\\n\", %d), which returned %d\n",fd, strlen("cs3377\n"), sz);

	close(fd);



/*
	int i, stat;
	pid_t pid; 
	
	int p[2];

	int win;
	int loss;

	for (i=0; i<numOfT; i++) { 
		pid = fork();

		if (pid == 0) {
			sleep(1);
			stat = execv("./hand", &argv[1]);
			exit(0);
		} else {
			if (verbose) {
                      		 printf("PID %d return\n ", pid);
			}
			
			pid = wait(&stat);
			
			if (WEXITSTATUS(stat) == 0) {		// Failure
				win++;
			} else {
				loss++;
			}
		}
	}
	win = numOfT - loss;
	double lossP = (double)loss / (double)numOfT;
	lossP = lossP * 100;
	
	int lossPP = (int)lossP;
	int winPP = 100 - lossPP;
	//printf("Success %d\n", win);
	//printf("Failure %d\n", loss);
	printf("Created %d processes.\n", numOfT);
	printf("Success -  %d%%\n", winPP);
	printf("Failure -  %d%%\n", lossPP);
*/			
	return 0;
}
