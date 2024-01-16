/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/27 06:21:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_data(t_data *data, int ac, char *av[], char **envp)
{
	ft_memset(data, 0, sizeof(data));
	data->ac = ac;
	data->av = av;
	data->envp = envp;
}

char	**init_candidate(t_data data)
{
	while (*data.envp)
	{
		if (ft_strncmp(*data.envp, "PATH=", 5) == IDENTICAL)
		{
			*data.envp += 5;
			break ;
		}
		data.envp++;
	}
	return (ft_split(*data.envp, ':'));
}

void	solve_pipe(int i, t_data data, int fd[2][2])
{
	pid_t	pid;

	if (ft_strcmp(data.av[++i], "here_doc"))
		input_data_redirection(data.av[1], fd);
	else
	{
		data.here_doc = TRUE;
		here_doc_input_redirection(data, fd);
		i++;
	}
	while (++i < data.ac - 1)
	{
		if (pipe(fd[IPC]) < 0)
			exit_msg_program("Failed to create PIPE");
		pid = fork();
		if (pid < 0)
			exit_msg_program("Failed to fork process");
		if (pid == CHILD)
			child_process(data, fd, i);
		parent_process(data, fd, i);
	}
}

void	pipex(t_data data, int fd[2][2], int _stdin, int i)
{
	stdin_manipulation(&_stdin, DUPLICATE_TEMP);
	solve_pipe(i, data, fd);
	wait_child_pid();
	stdin_manipulation(&_stdin, RESTORE_STDIN);
}

int	main(int ac, char *av[], char *envp[])
{
	// dup2(0, 3);
	// close(0);
	// dup2(3, 0);
	// char *cmd[] = {"cat", NULL};
	// execv("/bin/cat", cmd);
	// int fdss[2];
	// printf("%d\n", pipe(fdss));
	// printf("%d\n", pipe(fdss));
	// return (0);
	t_data	data;
	int		fd[2][2];
	int		_stdin;
	int		i;

	i = 0;
	_stdin = 0;
	if (ac < 5)
		exit_msg_program("Invalid argument count");
	init_data(&data, ac, av, envp);
	pipex(data, fd, _stdin, i);
	return (0);
}
