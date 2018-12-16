#include<stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "mytools.h"

int main(int argc, char **argv)
{
	int percent;
	percent = atoi(argv[optind]);

	float randomNum;
	int randomPercent;	
	
	assert(init_mytool() == 0);

	randomNum = get_random_number();
	randomNum = randomNum * 100;
	randomPercent = int(randomNum);
	
	finalize_mytool();

	//printf("The random number is: %d\n", randomPercent);

	if (randomPercent <= percent) {
		printf("Success!\n");
		return 0;
	} else {
		printf("Failure!\n");
		return 1;
	}


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
