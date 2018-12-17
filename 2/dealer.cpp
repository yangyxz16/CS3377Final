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
void createProcess(int percent, int numOfT, bool v);
void create9000Process(int numOfT);
void checkPT(int percent, int numOfT);

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

	checkPT(percent, numOfT);

	printf("%s\n", fileName);

	int fd, sz;

	fd = open(fileName, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0) { perror("r1"); exit(1); }

	write(fd, "cs3377\n", strlen("cs3377\n"));


	close(fd);


	createProcess(percent, numOfT, verbose);
	create9000Process(numOfT);
	return 0;
}

void createProcess(int percent, int numOfT, bool v) {
	int i, stat;
	pid_t pid;
	int win = 0;	// Counter for success.
	int loss = 0;   // Counter for failure.
	int total = 0;	// Total processes created.
	char arg1[20];
	snprintf(arg1, sizeof(arg1), "%d", percent);     // Change percent(int) to string.
	
	for (i=0; i<numOfT; i++) {
		pid = fork();

		if (pid == 0) {
			sleep(1);
			stat = execl("./hand", "./hand", arg1, NULL); 
			exit(0);
		 } else {
		 	if (v) {
				printf("PID %d return\n ", pid);
			}

			pid = wait(&stat);

			if (WEXITSTATUS(stat) == 0) {       
				win++;
			} else {
				loss++;
			}
			
			total++;
		}
	}
	
	win = total - loss;
	double lossP = (double)loss / (double)total;
	lossP = lossP * 100;
	int lossPP = (int)lossP;        // Percentage of failure.
	int winPP = 100 - lossPP;       // Percentage of success;

	printf("Created %d processes.\n", total);
	printf("Success -  %d%%\n", winPP);
	printf("Failure -  %d%%\n", lossPP);
}

void create9000Process(int numOfT) {
	int stat;
	pid_t pid; 
	int startP = 10; //Starting percentage.
	char arg1[20];

	while (startP <= 90) {
		int win = 0;	// Counter for success.
		int loss = 0;   // Counter for failure.
		int total = 0;  // Total processes created.
		
		snprintf(arg1, sizeof(arg1), "%d", startP);	// Change startP(int) to string.
		for (int i=0; i<numOfT; i++) { 
			pid = fork();

			if (pid == 0) {
				sleep(1);
				stat = execl("./hand", "./hand", arg1, NULL);	// Starting at 10 percent, 
								// incrementing by 10 until get to input percent
				exit(0);
			} else {	
				pid = wait(&stat);
			
				if (WEXITSTATUS(stat) == 0) {		// Failure
					win++;
				} else {
					loss++;
				}

				total++;
			}
		}
		
		win = total - loss;
		double lossP = (double)loss / (double)total;
		lossP = lossP * 100;
		int lossPP = (int)lossP;        // Percentage of failure.
		int winPP = 100 - lossPP;       // Percentage of success;
		
		printf("Percentage: %d%%\n", startP);
		printf("Created %d processes.\n", total);
		printf("Success -  %d%%\n", winPP);
		printf("Failure -  %d%%\n", lossPP);
		startP+=10;
	
	}
}


void checkPT(int percent, int numOfT)
{	
	if (percent > 100) {
		fprintf(stderr, "The percentage cannot be larger than 100!\n");
		exit(-1);
	}

	 if (numOfT == 0) {
	 	fprintf(stderr, "The number of trails is invaild!\n");
		exit(-1);
	}
}


