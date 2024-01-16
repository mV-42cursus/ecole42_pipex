/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:20:31 by marvin            #+#    #+#             */
/*   Updated: 2023/07/22 00:35:42 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

extern char **environ;

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define CHILD 0
# define PIPIN_FILENO 0 // read
# define PIPOUT_FILENO 1 // write

int main()
{
	int fd[2];
	
	pipe(fd);
	pid_t pid = fork();
	if (pid == CHILD) {
		int outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[PIPIN_FILENO], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		char *cmd[20] = {"cat", NULL};
		execv("/bin/cat", cmd);
	} else {
		write(fd[PIPOUT_FILENO], "hello", 5);
		write(fd[PIPOUT_FILENO], "hello", 5);
		write(fd[PIPOUT_FILENO], "hello", 5);
		write(fd[PIPOUT_FILENO], "hello", 5);
		write(fd[PIPOUT_FILENO], "hello", 5);
		write(fd[PIPOUT_FILENO], "hello", 5);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}
