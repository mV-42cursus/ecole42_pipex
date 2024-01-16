/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mng.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 23:20:49 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 16:22:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_program(void)
{
	exit(EXIT_FAILURE);
}

void	exit_msg_program(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	exit_free_program(char **candidate)
{
	while (*candidate)
		free(*candidate++);
	free(candidate);
	exit(EXIT_FAILURE);
}

void	exit_free_msg_program(char *str, char **__argv, char **candidate)
{
	int	i;

	i = 0;
	perror(str);
	while (__argv[i])
		free(__argv[i++]);
	free(__argv);
	i = 0;
	while (candidate[i])
		free(candidate[i++]);
	free(candidate);
	exit(EXIT_FAILURE);
}
