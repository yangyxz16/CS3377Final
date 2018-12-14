#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double randomGenerator(double min, double max);

int main(int argc, char *argv[])
{
	int n = 10;
	double r[n];

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		r[i] = randomGenerator(0, 1);
		printf("%g\n", r[i]);
	}
	return 0;
}

double randomGenerator(double min, double max)
{
	return min + (max - min) * rand() / ((double) RAND_MAX);
}

