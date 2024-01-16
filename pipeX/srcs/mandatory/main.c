/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:22:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	pipex(t_data data, int fd[2][2], int _stdin, int i)
{
	stdin_manipulation(&_stdin, DUPLICATE_TEMP);
	solve(i, data, fd);
	wait_child_pid();
	stdin_manipulation(&_stdin, RESTORE_STDIN);
}

int	main(int ac, char *av[], char *envp[])
{
	t_data	data;
	int		fd[2][2];
	int		_stdin;
	int		i;

	i = 1;
	_stdin = 0;
	if (ac != 5)
		exit_msg_program("Invalid argument count");
	init_data(&data, ac, av, envp);
	pipex(data, fd, _stdin, i);
	return (0);
}
