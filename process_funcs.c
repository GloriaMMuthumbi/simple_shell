#include "main.h"
/**
 * child_process - runs the child process
 * @command: command to be executed
 * @args: array of strings
 * @pipe_fd - array of file descriptors
 * Return: returns nothing
 */
void child_process(char *command, char **args, int pipe_fd[2])
{
	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);

	if (execve(command, args, environ) == -1)
	{
		perror("./hsh");
		free(args);
		exit(EXIT_FAILURE);
	}
	fflush(stdout);
}

/**
 * parent_process - runs the parent process
 * @pipe_fd - array of file descriptors
 * Return: returns nothing
 */
void parent_process(int pipe_fd[2])
{
	char buffer[BUFSIZ];
	ssize_t read_bytes;

	close(pipe_fd[1]);

	while ((read_bytes = read(pipe_fd[0], buffer, sizeof(buffer))) > 0)
	{
		while (read_bytes > 0 && (buffer[read_bytes - 1] == '\n'
					|| buffer[read_bytes - 1] == ' '
					|| buffer[read_bytes - 1] == '\t'))
			--read_bytes;
		write(STDOUT_FILENO, buffer, read_bytes);
	}
	close(pipe_fd[0]);
}
