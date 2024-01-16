/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:09:32 by marvin            #+#    #+#             */
/*   Updated: 2023/07/21 19:09:56 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define TRUE 1
# define FALSE 0

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

# define HERE_DOC 1

typedef struct s_data {
	char	**av;
	char	**envp;
	int		ac;
	int		here_doc;
}	t_data;

void	init_data(t_data *data, int ac, char *av[], char **envp);
char	**init_candidate(t_data data);
void	pipex(t_data data, int fd[2][2], int _stdin, int i);
void	solve_pipe(int i, t_data data, int fd[2][2]);
int		main(int ac, char *av[], char *envp[]);

void	execute_process(t_data data, int i);
void	child_process(t_data data, int fd[2][2], int i);
void	parent_process(t_data data, int fd[2][2], int i);
void	wait_child_pid(void);
void	here_doc_input_redirection(t_data data, int fd[2][2]);

void	exit_program(void);
void	exit_msg_program(char *str);
void	exit_free_program(char **candidate);
void	exit_free_msg_program(char *str, char **__argv, char **candidate);

void	input_data_redirection(char *file_name, int fd[2][2]);
void	output_data_redirection(t_data data, int fd[2][2]);
void	stdin_manipulation(int *_stdin, int flag);

#endif
