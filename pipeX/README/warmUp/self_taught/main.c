/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:20:31 by marvin            #+#    #+#             */
/*   Updated: 2023/07/17 03:01:10 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

extern char **environ;

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>

# define CHILD 0
# define PIPIN_FILENO 0 // read
# define PIPOUT_FILENO 1 // write
// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	(void)argv;
// 	printf("current process id : %d\n", getpid());
// 	int pipe_fd[2];
// 	pipe(pipe_fd);
// 	int fd2 = open("infile", O_RDONLY);
// 	char *tmp[10] = {"ls", "-al", NULL};
// 	char *tmp2[10] = {"wc", "-l", NULL};
// 	int pid1 = fork();
// 	if (pid1 == CHILD)
// 	{
// 		/* STDIN 역할을 하는게 아니라 fd2가 0의 자리로 가서 STDIN_FILENO자리에 file descriptor2의 데이터를 넘김 */
// 		// close(pipe_fd[WRITE]);
// 		dup2(fd2, STDIN_FILENO);
// 		dup2(pipe_fd[WRITE], STDOUT_FILENO);
// 		dup2(pipe_fd[READ], STDIN_FILENO);
// 		execv("/bin/ls", tmp);
// 	}
// 	int outfile_fd = open("outfile", O_CREAT | O_WRONLY | O_TRUNC);
// 	dup2(pipe_fd[READ], STDIN_FILENO);
// 	dup2(outfile_fd, STDOUT_FILENO);
// 	close(outfile_fd);
// 	execv("/bin/wc", tmp2);
// 	wait(NULL);
// 	return (0);
// }

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	printf("current process id : %d\n", getpid());
	int _fd[2];
																		// write(3, "hello", 5);
																		// char buffer[100];
																		// read(3, buffer, 5);
																		// printf("%s\n", buffer);
																		// while (1) {
																		// 	write(1, "heredoc> ", 9);
																		// 	char *str = get_next_line(STDERR_FILENO);
																		// 	if (str == NULL)
																		// 		return (0);
																		// 	printf("%s", str);
																		// }
	pipe(_fd);
	int fd2 = open("infile", O_RDONLY);
												//////////////////////////////////////		
												char *tmp[10] = {"cat", NULL};
												char *tmp2[10] = {"cat", NULL};
												//////////////////////////////////////
	int pid1 = fork();
	if (pid1 != CHILD)
	{
		dup2(fd2, STDIN_FILENO); 					// 너 원래 STDIN에다 읽어오는 애지 -> 그냥 fd2 오픈한 파일에서 부터 읽어
													// STDIN 역할을 하는게 아니라 fd2가 0의 자리로 가서
													// dup2(pipe_fd[READ], STDIN_FILENO);
														// printf("printf");
														// write(STDOUT_FILENO, "hello", 5);
		dup2(_fd[PIPOUT_FILENO], STDOUT_FILENO);		// ㄴㅓ ㅇㅝㄴ래 stdout에다 쓰는애지 -> 그냥 파이프에다가 써
		execv("/bin/cat", tmp);						// 이 결과가 원래는 표준 출력에 나오는데 지금 현재 속여버려서 파이프에다가 쓴 상태이다
	}
	// char buffer[100];
	// read(pipe_fd[READ], buffer, 100);
	// printf("%s", buffer); // 자식에서 속인것은 부모는 모름 ㅋ
	int output_fd = open("./outfile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	/* 
		// dup2(_fd[PIPIN_FILENO], STDIN_FILENO);
		outfile 에 적어줘
		뭘 적어? -> 파이프에 적혀진걸 적
							Makefile
							README
							README.md
							header
							infile
							kkk
							objs
							outfile
							pipex
							srcs
	*/
	close(_fd[PIPOUT_FILENO]);
																// char buff[100];
																// dup2(_fd[PIPIN_FILENO], STDIN_FILENO);
																// read(_fd[PIPIN_FILENO], buff, 20);
																// write(STDOUT_FILENO, buff, 25);
	dup2(_fd[PIPOUT_FILENO], STDOUT_FILENO);
	dup2(output_fd, STDOUT_FILENO);	
																																				// char buffer[1000];
																																				// read(0, buffer, 1000);
																																				// printf("%s\n", buffer);
	execv("/bin/cat", tmp2);
	// 																															// char pipe_buf[1000];
																																// read(pipe_fd[READ], pipe_buf, 100);
																																// printf("test buf:%s\n", pipe_buf);
																																// puts("@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
																																// char buffer[100];
																																// write(pipe_fd[WRITE], "hello", 5);
																																// read(pipe_fd[READ], buffer, 6); // READ -> blocking (프로세스 받을떄까지 종료안함)
																																// close(pipe_fd[READ]);
																																// close(pipe_fd[WRITE]);
																																// printf("%s\n", buffer);
	wait(NULL);
	return (0);
}

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	(void)argv;
// 	int _fd[2];

// 	// char *argv1[10] = {"cat", "-e", "", NULL};
// 	// int fd = open("./srcs/mandatory/test.txt", O_RDONLY);
// 	if (pipe(_fd) == -1)
// 		exit(EXIT_FAILURE);
// 	int pid1 = fork();
// 	if (pid1 < 0)
// 		exit(EXIT_FAILURE);
// 	if (pid1 == CHILD)
// 	{
// 		// child process 1
// 		dup2(_fd[0], STDIN_FILENO); // ㄱㅏ르키는게 달달라라짐 + 어어디서 들들어어오오고  어어디로 나나가가는는지  설설정정해해주주는  게  덥2
// 		close(_fd[0]);
// 		close(_fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}
// 	int pid2 = fork();
// 	if (pid2 < 0)
// 		exit(EXIT_FAILURE);
// 	if (pid2 == CHILD)
// 	{
// 		dup2(_fd[WRITE], STDIN_FILENO);
// 		close(_fd[READ]);
// 		close(_fd[WRITE]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}
// 	close(_fd[READ]);
// 	close(_fd[WRITE]);
// 	waitpid(pid1, NULL, 0);
// 	// waitpid(pid2, NULL, 0);
// 	return (0);
// }

// extern char **environ;

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	(void)argv;

// 	char *argv1[10] = {"cat", "-e", NULL};
// 	int fd = open("./srcs/mandatory/test.txt", O_RDONLY);
// 	printf("-->> %d\n", fd);
// 	dup2(fd, STDIN_FILENO);
// 	printf("-->> %d\n", fd);
// 	execve("/bin/cat", argv1, environ);
// 	return (0);
// }
