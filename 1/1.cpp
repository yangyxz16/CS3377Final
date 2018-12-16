#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <cmath>
#include <ctime>
#include <assert.h>
#include <unistd.h>
#include <cstdlib>
#include "mytools.h"

double paiLoop(int point); 
//double randomGenerator(double min, double max);
int main(int argc, char **argv)
{
	int Start = clock();
	
	int points = 10000;	// Number of points.
	
	double r[10];
	double sum = 0;
	double sd = 0;

	for (int i = 0; i < 10; i++) {
		r[i] = paiLoop(points);
		sum += r[i];
		sleep(1);
	}
	
	double avg = sum / 10;

	for (int i = 0; i < 10; ++i) {
		sd += pow(r[i] - avg, 2);
	}

	sd = sqrt(sd / 10);

	double error = (avg - 3.14159265359) * 100 / 3.14159265359 ;
	
	if (error < 0) {
		error = error * -1;
	}		

	printf("Average of 10 trails is: %g\n", avg);
	printf("Standard Deviation is: %g\n", sd);
	printf("Percentage error is: %g percent\n", error);
	int stop_s=clock();
	//printf("Time taken: %.9fs\n", (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000);
	//printf("Time taken: %.9fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC*1000);
	printf("Time taken: %f\n", (float)Start / CLOCKS_PER_SEC);
	return 0;
}

double paiLoop(int point)
{
	double x;
	double y;
	double d;
	int numInC = 0;     // Number points in quarter unit circle.
	assert(init_mytool() == 0);
	
	for (int i = 0; i < point; i++) {
		x = get_random_number();
		y = get_random_number();
		d = sqrt(pow(x,2) + pow(y,2));
		if (d <= 1) { 
			numInC++; 
		}
	}
	finalize_mytool();
	
	double pai = 4 * (numInC / (double)point); 
	return pai;
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

