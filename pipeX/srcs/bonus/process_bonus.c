/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:45:41 by marvin            #+#    #+#             */
/*   Updated: 2023/07/27 06:40:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	fprintf(stderr, "---- CHILD PROCESS ----\n");
	fprintf(stderr, "i: %d || IN: %d OUT: %d\n", i, fd[IPC][PIPIN_FILENO], fd[IPC][PIPOUT_FILENO]);
	if (i == data.ac - 2)
		output_data_redirection(data, fd);
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
	fprintf(stderr, "---- PARENT PROCESS ----\n");
	fprintf(stderr, "i: %d || IN: %d OUT: %d\n", i, fd[IPC][PIPIN_FILENO], fd[IPC][PIPOUT_FILENO]);
	if (i == data.ac -2)
		close(STDIN_FILENO);
	// ///////////////////////////////////////////////////////////////////
	// if (i == 2)
	// {
	// 	char buffer[100000];
	// 	read(fd[IPC][PIPIN_FILENO], buffer, 10000);
	// 	fprintf(stderr, "%s", buffer);
	// }
	// ///////////////////////////////////////////////////////////////////
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

void	here_doc_input_redirection(t_data data, int fd[2][2])
{
	char	*line;

	pipe(fd[IPC]); 
	while (1)
	{
		ft_putstr_fd("here_doc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (!ft_strncmp(line, data.av[2], ft_strlen(data.av[2])) \
			&& ft_strlen(line) == ft_strlen(data.av[2]) + 1)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd[IPC][PIPOUT_FILENO]);
		free(line);
	}
	close(fd[IPC][PIPOUT_FILENO]);
	dup2(fd[IPC][PIPIN_FILENO], STDIN_FILENO);
	close(fd[IPC][PIPIN_FILENO]);
}
