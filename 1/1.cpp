#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<cmath>
#include <ctime>

double randomGenerator(double min, double max);

int main(int argc, char *argv[])
{
	//clock_t tStart = clock();
	int n = 10000;	// Number of points.
	
	double r[n];
	double x;
	double y;
	double d;
	
	int numInC;	// Number points in quarter unit circle.

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		x = randomGenerator(0, 1);
		y = randomGenerator(0, 1);
		d = sqrt(pow(x,2) + pow(y,2));
		if (d <= 1) {
			numInC++; 
		}

	}
	
	double pai = 4 * (numInC / (double)n);
	printf("%g\n", pai);
	//int stop_s=clock();
	//printf("Time taken: %.9fs\n", (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000);
	//printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC*1000000);
	return 0;
}

double randomGenerator(double min, double max)
{
	return min + (max - min) * rand() / ((double) RAND_MAX);
}

