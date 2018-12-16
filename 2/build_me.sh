Compile hand.cpp:
-I$HOME/local/gsl-2.5/include hand.cpp -lgsl -lgslcblas -L$HOME/local/gsl-2.5/lib

Change "a.out"(the compiled hand.cpp) to "hand":
cp a.out hand

Export library:
export LD_LIBRARY_PATH=$HOME/local/gsl-2.5/lib
