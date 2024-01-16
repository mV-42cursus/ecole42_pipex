/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/19 23:30:30 by marvin           ###   ########seoul.kr  */
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
	if (fd[FILE][INFILE] == OPEN_ERROR)
		exit_program("Infile open error");
	dup2(fd[FILE][INFILE], STDIN_FILENO);
	printf("should be opened: %d\n", isFDOpen(fd[FILE][INFILE]));
	close(fd[FILE][INFILE]);
	printf("should be close: %d\n", isFDOpen(fd[FILE][INFILE]));
}

void	output_data_direction(char *file_name, int fd[2][2])
{
	fd[FILE][OUTFILE] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[FILE][OUTFILE] == OPEN_ERROR)
		exit_program("Outfile open error");
	dup2(fd[FILE][OUTFILE], STDOUT_FILENO);
	close(fd[FILE][OUTFILE]);
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
	printf("should be close: %d\n", isFDOpen(fd[FILE][INFILE]));
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	while (++i < argc - 1)
	{
		pipe(fd[IPC]);
		pid_t pid;
		pid = fork();
		if (pid == CHILD)
		{
			// ./pipex   infile   cmd1    cmd2    outfile
			// ./pipex   infile   cat     ls      outfile
			// ./pipex   infile   ls      cat     outfile
			// ./pipex   infile   wc -l   ls      outfile
			// ./pipex   infile   ls      wc -l   outfile
			if (i == argc - 2)
				output_data_direction(argv[i + 1], fd);
			else		
				dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
			close(fd[IPC][PIPOUT_FILENO]);
			close(fd[IPC][PIPIN_FILENO]);
			if (i == 2)
			{
				char *cmd1[10] = {"cat", NULL};
				execv("/bin/cat", cmd1);
			}
			if (i == 3)
			{
				char *cmd2[10] = {"ls", NULL};
				execv("/bin/ls", cmd2);
			}
			// if (i == 5 )
			// {
			// 	char *cmd4[10] = {"wc", "-l", NULL};
			// 	execv("/usr/bin/wc", cmd4);
			// }

			// execv(parsing_output, parsing_output2);
		}
		if (i < argc - 2)
			dup2(fd[IPC][PIPIN_FILENO], STDIN_FILENO);
		close(fd[IPC][PIPOUT_FILENO]);
		close(fd[IPC][PIPIN_FILENO]);
	}
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	////////////////////////////////////////////////////
	while (wait(NULL) != -1)
		;
	return (0);
}

/*
	--------------------- [1] ----------------------
	./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
	< file1 cmd1 | cmd2 | cmd3 ... | cmdN > file2

|	-> CASE[MANDATORY]
|	./pipex  file1   cmd1   cmd2   file2
|	av[0]    av[1]   av[2]  av[3]  av[4]
|	
|	< file1  cmd1 | cmd2 > file2

|	-> CASE[BONUS: BASIC]
|	./pipex  file1  cmd1   cmd2   cmd3   file2
|	 av[0]   av[1]  av[2]  av[3]  av[4]  av[5] 
|	< file1 cmd1 | cmd2 | cmd3 > file2

	--------------------- [2] -----------------------
	./pipex here_doc LIMITER cmd cmd1 file
	cmd << LIMITER | cmd1 >> file			
*/

// ./pipex  file1  cmd1   cmd2   cmd3   file2
// < file1 cmd1 | cmd2 | cmd3 > file2
// 			   o/p    o/p
