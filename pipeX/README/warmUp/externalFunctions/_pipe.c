/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:38:49 by marvin            #+#    #+#             */
/*   Updated: 2023/07/11 19:04:32 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	pipe(int fildes[2]);

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# define READ 0
# define WRITE 1

int main(void) {
	int pipe_fd[2]; // pipe_fd[1] -> write
				   	// pipe_fd[0] -> read
	pipe(pipe_fd);
	pid_t child_pid = fork();
	if (child_pid == 0) {
		close(pipe_fd[READ]);
		dup2(pipe_fd[WRITE], STDOUT_FILENO);
		printf("this is child\n");
	}	else {
		close(pipe_fd[WRITE]);
		dup2(pipe_fd[READ], STDIN_FILENO);
		char *buff = calloc(100, sizeof(char));
		read(0, buff, 10);
		printf("this is parent, read from pipe: %s\n", buff);
		free(buff);
	}
	return (0);
}

/* 
	pipe 함수는 이름 그대로 pipe를 생성하고...fd를 할당해준다.
	pipe는 쓰는 쪽과 읽는 쪽, 2개의 fd가 할당되며 할당된 fd는 인자로 넣어준 int 배열 fildes에 담기게 된다.
	pipe_fd[1]쪽에 써서 pipe_fd[0]에서 읽을 수 있다.
	한 개의 프로세스 내에서 pipe를 이용할 수 도 있지만 주로 프로세스 사이에 데이터를 주고받기 위해 이용된다.
	pipe 함수는 성공시 0, 실패시 -1을 반환한다.
	위 코드에서 자식 프로세스에서 pipe_fd[1]에 메세지를 쓰면 부모 프로세스에서 pipe_fd[0]을 통해 읽어올 수 있다.
*/
