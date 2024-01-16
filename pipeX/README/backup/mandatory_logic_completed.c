/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_logic_completed.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/18 06:51:15 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int isFDOpen(int fd) {
    int flags = fcntl(fd, F_GETFL);

    if (flags == -1) {
        // Error occurred while checking the file descriptor
        return 0;
    }

    // File descriptor is open if it doesn't have the O_CLOEXEC flag
    return !(flags & O_CLOEXEC);
}

void	init_data(t_data *data, int argc, char *argv[], char **envp)
{
	ft_memset(data, 0, sizeof(data));
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
}

void	input_data_direction(char *file_name, int fd[2][2])
{
	fd[FILE][INFILE] = open("/dev/random", O_RDONLY);
	dup2(fd[FILE][INFILE], STDIN_FILENO);
	close(fd[FILE][INFILE]);
}

int main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int	fd[2][2];
	int	i;

	i = 0;
	if (argc < 5)
		exit_program("Invalid argument count");
	init_data(&data, argc, argv, envp);
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	i++;
	fd[FILE][INFILE] = open("/dev/random", O_RDONLY);
	dup2(fd[FILE][INFILE], STDIN_FILENO);
	close(fd[FILE][INFILE]);
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	int _stdin = dup(STDIN_FILENO);
	while (++i < argc - 1)
	{
		pid_t pid;

		pipe(fd[IPC]);
		pid = fork();
		if (pid == CHILD)
		{
			if (i == argc - 2)
			{
				fd[FILE][OUTFILE] = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
				dup2(fd[FILE][OUTFILE], STDOUT_FILENO);
				close(fd[FILE][OUTFILE]);
			}
			else
				dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
			close(fd[IPC][PIPOUT_FILENO]);
			close(fd[IPC][PIPIN_FILENO]);
			if (i == 2)	{
				char *cmd1[10] = {"cat", NULL};
				execv("/bin/cat", cmd1);
			}
			if (i == 3)	{
				char *cmd2[10] = {"ls", NULL};
				execv("/bin/ls", cmd2);
			}
			if (i == 4) {
				char *cmd3[10] = {"cat", "-e", NULL};
				execv("/bin/cat", cmd3);
			}
			if (i == 5) {
				char *cmd4[10] = {"ls", NULL};
				execv("/bin/ls", cmd4);
			}
			if (i == 5) {
				char *cmd4[10] = {"ls", NULL};
				execv("/bin/ls", cmd4);
			}
			if (i == 6) {
				char *cmd4[10] = {"ls", "-al", NULL};
				execv("/bin/ls", cmd4);
			}
		}
		close(STDIN_FILENO);
		if (i != argc - 2)
			dup2(fd[IPC][PIPIN_FILENO], STDIN_FILENO);
		close(fd[IPC][PIPOUT_FILENO]);
		close(fd[IPC][PIPIN_FILENO]);
	}
	while (wait(NULL) > 0)
		;
	dup2(_stdin, STDIN_FILENO);
	close(_stdin);
	return (0);
	//////////////////////////////////////////////
	//////////////////////////////////////////////
	//////////////////////////////////////////////
}
