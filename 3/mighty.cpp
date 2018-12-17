#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv) 
{
	pid_t pid;
	int fd[2];	// fd[0] is the read end; fd[1] is the write end.
	pipe(fd);
	pid = fork();

	if(pid == 0) {	// Child process.
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execl("/usr/bin/cat", "/usr/bin/cat", "-b", argv[1], (char *)NULL); // Execute the “cat –b” command.
		fprintf(stderr, "Failed to execute '%s'\n", "cat");	// Standard error.
		exit(1);
	} else {	// Parent process.
		pid=fork();

		if(pid==0)
		{
			dup2(fd[0], STDIN_FILENO);
			close(fd[1]);
			close(fd[0]);
			execlp("/usr/bin/tee", "/usr/bin/tee", argv[2], (char *)NULL); // Execute the “tee” command.
			fprintf(stderr, "Failed to execute '%s'\n", "tee");	// Standard error.
			exit(1);
		} else {
			int status;
			close(fd[0]);
			close(fd[1]);
			waitpid(pid, &status, 0);
		}
	}

	return 0;
}
