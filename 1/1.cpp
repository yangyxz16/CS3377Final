#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <ctime>
#include <assert.h>
#include "mytools.h"

//double randomGenerator(double min, double max);
int main(int argc, char **argv)
{
	//clock_t tStart = clock();
	int n = 10000;	// Number of points.
	
	double r[n];
	double x;
	double y;
	double d;
	
	int numInC;	// Number points in quarter unit circle.

	//srand(time(NULL));
	assert(init_mytool() == 0);
	
	for (int i = 0; i < n; i++) {
		//x = randomGenerator(0, 1);
		//y = randomGenerator(0, 1);
		x = get_random_number();
		y = get_random_number();
		d = sqrt(pow(x,2) + pow(y,2));
		if (d <= 1) {
			numInC++; 
		}
	}

	finalize_mytool();

	double pai = 4 * (numInC / (double)n);
	printf("%g\n", pai);
	//int stop_s=clock();
	//printf("Time taken: %.9fs\n", (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000);
	//printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC*1000000);
	return 0;
}


int init_mytool()
{
        _gsl_rng = gsl_rng_alloc(gsl_rng_mt19937);
	gsl_rng_set(_gsl_rng, time(NULL));

	if(_gsl_rng == NULL)
		return 1;
	else
		return 0;
}

void finalize_mytool()
{
	gsl_rng_free (_gsl_rng);
	return;
}

double get_random_number()	
{
	return(gsl_rng_uniform (_gsl_rng));
}

/*double randomGenerator(double min, double max)
{
	return min + (max - min) * rand() / ((double) RAND_MAX);
}*/

