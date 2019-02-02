# CS3377UNIX-Final

-Problem 1: basic UNIX, bash scripting, compiled vs interpreted languages

Compute an estimate of π. As we know, the area of a circle of radius (r) is A = π r2. 
A circle with r = 1 is called the unit circle and has an area π, so the area of one fourth of the unit circle is π / 4. 
In a unit square, that is a square with sides of length one, with an “inscribed” quarter unit circle.
The ratio of the number of points inside the quarter circle to the total number of points in the square should ideally be the same as the ratio of the area of the quarter circle to the area of the square.
A C/C++ program to calculate π using the above information together with a random number generator to perform a “monte carlo” simulation.

-Problem 2: Binary File I/O

Start with the same codes that created for project "CS3377UNIX-fork-wait-exec", Dealer and Hand. 
Augment dealer so that it can take an additional input option, -o filename. 
This filename will be a binary file that contains the results of the simulation. 
If filename does not exist, the program dealer will create the file. 
If filename does exist, then simply append the results to the end of the file.
Once the dealer program can save statistics to filename, 
run it with 1000 trials per percentage “-p” starting with an input percentage of 10 and incrementing by 10 until get to 90% for a total of 9 x 1000 trials run.
Finally, create a program named pitboss. 
This program will take two arguments, the Dealer output file thatparse as well as the “-p” value from the above runs for which it is to generate statistics.

-Problem 3: Fork, exec, and pipes

UNIX systems include a program (filter) that copies standard input to standard output and a file descriptor passed on the command line at the same time. This program is tee.
This progeam generate our my version of tee called mighty, which will be equivalent to the “cat –b …” command. 

Details:

1. Error check the CLI input:
argv[1] will be the input file that’s going to get “tee”’d, argv[2] will be the file you write to
2. Create a pipe
3. Fork the process
4. Child will: call dup2 so that any writes to standard output will go instead of the write end of the pipethen execute the “cat –b” command using “execl”
5. Parent will: open argv[2] for writing, read from the pipe until there are no characters left, write to STDOUT, write to the fire descriptor associated with argv[2]

-Bonus 2: 

This is a computer program that calculates and prints out all “ugly numbers” below 10000. Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included.
