/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:41:48 by marvin            #+#    #+#             */
/*   Updated: 2023/09/12 01:36:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_process(t_data data, int i)
{
	char	*__path;
	char	*_path;
	char	**__argv;
	char	**__envp;
	char	**candidate;

	__argv = ft_split_quotation(data.av[i], ' ');
	__envp = data.envp;
	candidate = init_candidate(data);
	i = 0;
	while (candidate[i])
	{
		_path = ft_strjoin_free(candidate[i++], "/", NONE);
		__path = ft_strjoin_free(_path, __argv[0], NONE);
		execve(__path, __argv, __envp);
		free(_path);
		free(__path);
	}
	exit_free_msg_program(__argv[0], __argv, candidate);
}

void	child_process(t_data data, int fd[2][2], int i)
{
	if (i == data.ac - 2)
		output_data_redirection(data.av[data.ac - 1], fd);
	else
		dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
	close(fd[IPC][PIPOUT_FILENO]);
	close(fd[IPC][PIPIN_FILENO]);
	if (fd[FILE][INFILE] == ERROR && i == 2)
		exit(EXIT_FAILURE);
	execute_process(data, i);
}

void	parent_process(t_data data, int fd[2][2], int i)
{
	close(STDIN_FILENO);
	if (i != data.ac - 2)
		dup2(fd[IPC][PIPIN_FILENO], STDIN_FILENO);
	close(fd[IPC][PIPOUT_FILENO]);
	close(fd[IPC][PIPIN_FILENO]);
}

void	wait_child_pid(void)
{
	while (wait(NULL) != -1)
		;
}

void	solve(int i, t_data data, int fd[2][2])
{
	pid_t	pid;

	input_data_redirection(data.av[1], fd);
	while (++i < data.ac - 1)
	{
		if (pipe(fd[IPC]) < 0)
			exit_msg_program("Failed to create PIPE");
		pid = fork();
		if (pid < 0)
			exit_msg_program("Faile to fork process");
		if (pid == CHILD)
			child_process(data, fd, i);
		parent_process(data, fd, i);
	}
}
