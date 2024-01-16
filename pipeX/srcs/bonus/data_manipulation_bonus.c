/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_manipulation_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:31:20 by marvin            #+#    #+#             */
/*   Updated: 2023/07/27 05:31:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	input_data_redirection(char *file_name, int fd[2][2])
{
	fd[FILE][INFILE] = open(file_name, O_RDONLY);
	if (fd[FILE][INFILE] == ERROR)
		perror("Infile error");
	dup2(fd[FILE][INFILE], STDIN_FILENO);
	close(fd[FILE][INFILE]);
}

void	output_data_redirection(t_data data, int fd[2][2])
{
	if (data.here_doc == TRUE)
		fd[FILE][OUTFILE] = open(data.av[data.ac - 1], \
						O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd[FILE][OUTFILE] = open(data.av[data.ac - 1], \
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[FILE][OUTFILE] == ERROR)
		exit_msg_program("Failed to open outfile");
	dup2(fd[FILE][OUTFILE], STDOUT_FILENO);
	close(fd[FILE][OUTFILE]);
}

void	stdin_manipulation(int *_stdin, int flag)
{
	if (flag == DUPLICATE_TEMP)
		*_stdin = dup(STDIN_FILENO);
	if (flag == RESTORE_STDIN)
	{
		dup2(*_stdin, STDIN_FILENO);
		close(*_stdin);
	}
}
