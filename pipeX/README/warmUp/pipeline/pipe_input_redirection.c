/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_input_redirection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:31:22 by marvin            #+#    #+#             */
/*   Updated: 2023/07/27 00:35:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	int fds[2];                      // an array that will hold two file descriptors
	int infile_fd = open("/dev/random", O_RDONLY);

	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);

	pipe(fds);
	pid_t pid = fork();
	if (pid == 0) {
		dup2(fds[1], STDOUT_FILENO);
		close(fds[0]);
		close(fds[1]);
		char *cmd[] = {(char *)"cat", NULL};   // create argument vector
		if (execvp(argv[0], cmd) < 0) exit(0);  // run sort command (exit if something went wrong)
	}
	close(STDIN_FILENO);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
	close(fds[1]);
	char *cmd1[] = {(char *)"head", NULL};
	if (execvp(argv[0], cmd1) < 0) exit(0);
	while (wait(NULL) != -1)
		;
	return 0;
}
