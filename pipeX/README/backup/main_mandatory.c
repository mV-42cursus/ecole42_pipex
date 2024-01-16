/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/19 23:30:22 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(t_data *data, int argc, char *argv[], char **envp)
{
	ft_memset(data, 0, sizeof(data));
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
}

void	input_data_direction(char *file_name, int fd[2][2])
{
	fd[FILE][INFILE] = open(file_name, O_RDONLY);
	if (fd[FILE][INFILE] == OPEN_ERROR)
		exit_program("Infile open error");
	dup2(fd[FILE][INFILE], STDIN_FILENO);
	close(fd[FILE][INFILE]);
}

void	output_data_direction(char *file_name, int fd[2][2])
{
	fd[FILE][OUTFILE] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[FILE][OUTFILE] == OPEN_ERROR)
		exit_program("Outfile open error");
	dup2(fd[IPC][PIPIN_FILENO], STDIN_FILENO);
	dup2(fd[FILE][OUTFILE], STDOUT_FILENO);
	close(fd[IPC][PIPOUT_FILENO]);
	close(fd[FILE][OUTFILE]);
	close(fd[IPC][PIPIN_FILENO]);
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
	input_data_direction(argv[++i], fd);
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	pid_t pid;
	pipe(fd[IPC]);
	pid = fork();
	if (pid == CHILD)
	{
		// ./pipex   infile   cmd1    cmd2    outfile
		// ./pipex   infile   cat     ls      outfile
		// ./pipex   infile   ls      cat     outfile
		// ./pipex   infile   wc -l   ls      outfile
		// ./pipex   infile   ls      wc -l   outfile
		dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
		char *cmd1[10] = {"sleep", "2", NULL};
		execv("/bin/sleep", cmd1);
	}
	output_data_direction("outfile", fd);
	char *cmd2[10] = {"sleep", "2", NULL};
	execv("/bin/sleep", cmd2);
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	// wait(NULL);
	return (0);
}
