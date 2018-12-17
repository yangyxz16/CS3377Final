gcc -o hand -I$HOME/local/gsl-2.5/include hand.cpp -lgsl -lgslcblas -L$HOME/local/gsl-2.5/lib
gcc -o dealer dealer.cpp

