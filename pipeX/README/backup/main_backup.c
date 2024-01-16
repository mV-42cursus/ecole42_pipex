/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_backup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:38:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/19 23:30:37 by marvin           ###   ########seoul.kr  */
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

void	input_redirection(char *file_name, int fd[2][2])
{
	fd[FILE][INFILE] = open(file_name, O_RDONLY);
	if (fd[FILE][INFILE] == OPEN_ERROR)
		exit_program("Infile open error");
	dup2(fd[FILE][INFILE], STDIN_FILENO);
	close(fd[FILE][INFILE]);
}

void	output_redirection(char *file_name, int fd[2][2])
{
	fd[FILE][OUTFILE] = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[FILE][OUTFILE] == OPEN_ERROR)
		exit_program("Outfile open error");
	dup2(fd[FILE][OUTFILE], STDOUT_FILENO);
	close(fd[FILE][OUTFILE]);
}

// ///////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////
// void	mandatory(int fd[2][2], t_data data, char *argv[], int i)
// {
// 	// infile redirection
// 	// -> ./pipex < infile 이 부분 처리 중
// 	int pid;

// 	if (pipe(fd[IPC]) == -1)
// 		exit_program("Failed to create pipe");
// 	fd[FILE][OUTFILE] = open("outfile", O_WRONLY | O_TRUNC | O_CREAT, 0644);
// 	if (fd[FILE][INFILE] == OPEN_ERROR || fd[FILE][OUTFILE] == OPEN_ERROR)
// 		exit_program("Input file(infile) open error");
// 	pid = fork();
// 	if (pid == PID_ERROR)
// 		exit_program("Failed to create process");
// 	if (pid == CHILD)
// 	{
// 		dup2(fd[FILE][INFILE], STDIN_FILENO);
// 		dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
// 		char *cmd1[10] = {"cat", NULL};
// 		execv("/bin/cat", cmd1);
// 	}
// 	close(fd[IPC][PIPOUT_FILENO]);
// 	dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
// 	dup2(fd[FILE][OUTFILE], STDOUT_FILENO);
// 	char *cmd2[10] = {"ls", NULL};
// 	execv("/bin/ls", cmd2);
// }
// ///////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[], char *envp[])
{
	t_data	data;
	int	fd[2][2];
	int	i;

	i = 0;
	if (argc < 5)
		exit_program("Invalid argument count");
	init_data(&data, argc, argv, envp);

/*
	// printf("data.argc = %d\n", data.argc);
	// display_double_pointer_str(data.argv);
	// display_double_pointer_str(data.envp); 
*/

	input_redirection(argv[++i], fd);

	while (++i < argc - 1) // ./pipex infile "cat" "ls -al" "cat" outfile
	{	// 2 < 6 - 1 = 5
		/* [CHILD PROCESS] */
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		pid_t	pid;

		if (pipe(fd[IPC]) == -1)
			exit_program("Failed to create pipe");
		pid = fork();
		printf("process id: %d\n", pid);
		if (pid == -1)
			exit_program("Failed to create process");
		if (pid == CHILD)
		{
			/////////////////////////////////////////////
			/////////////////////////////////////////////
			if (i == data.argc - 2) // 4
				output_redirection(data.argv[i + 1], fd);
			else
				dup2(fd[IPC][PIPOUT_FILENO], STDOUT_FILENO);
           	close(fd[IPC][PIPOUT_FILENO]);
			close(fd[IPC][PIPIN_FILENO]);
			/////////////////////////////////////////////
			/////////////////////////////////////////////
			if (i == 2)
			{
				char *cmd1[10] = {
					"cat",
					NULL,
				};
				execv("/bin/cat", cmd1);
			}
			if (i == 3)
			{
				char *cmd2[10] = {
					"ls",
					"-al",
					NULL,
				};
				execv("/bin/ls", cmd2);
			}
			if (i == 4)
			{
				char *cmd3[10] = {
					"cat",
					NULL,
				};
				execv("/bin/cat", cmd3);
			}
		}
		////////////////////////////////////////////////////////////////////[]
		////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////
		if (i < data.argc - 2)
			dup2(fd[IPC][PIPIN_FILENO], STDIN_FILENO);
		close(fd[IPC][PIPOUT_FILENO]);
		close(fd[IPC][PIPIN_FILENO]);
	}
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
