/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:09:29 by marvin            #+#    #+#             */
/*   Updated: 2023/07/21 19:10:32 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define CHILD 0
# define PIPIN_FILENO 0 // READ
# define PIPOUT_FILENO 1 // WRITE

# define OPEN_ERROR -1
# define PIPE_ERROR -1
# define PID_ERROR -1
# define ERROR -1

# define DUPLICATE_TEMP 1
# define RESTORE_STDIN 0

# define FILE 1
# define INFILE 0
# define OUTFILE 1
# define IPC 0
# define PIPIN_FILENO 0
# define PIPOUT_FILENO 1

# define IDENTICAL 0

typedef struct s_data {
	char	**av;
	char	**envp;
	int		ac;
}	t_data;

void	input_data_redirection(char *file_name, int fd[2][2]);
void	output_data_redirection(char *file_name, int fd[2][2]);
void	stdin_manipulation(int *_stdin, int flag);

void	exit_program(void);
void	exit_msg_program(char *str);
void	exit_free_program(char **candidate);
void	exit_free_msg_program(char *str, char **__argv, char **candidate);

char	**init_candidate(t_data data);
void	pipex(t_data data, int fd[2][2], int _stdin, int i);
int		main(int ac, char *av[], char *envp[]);

void	execute_process(t_data data, int i);
void	child_process(t_data data, int fd[2][2], int i);
void	parent_process(t_data data, int fd[2][2], int i);
void	wait_child_pid(void);
void	solve(int i, t_data data, int fd[2][2]);

#endif
