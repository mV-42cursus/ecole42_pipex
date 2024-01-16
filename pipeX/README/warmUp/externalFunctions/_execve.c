/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _execve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 09:43:53 by marvin            #+#    #+#             */
/*   Updated: 2023/07/09 10:14:35 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	execve(const char *path, char *const argv[], char *const envp[]);

#include <stdio.h>
extern char **environ;

int main(void) {
	char *path = "/bin/ls";
	char *cmd[5];

	cmd[0] = "asdfasdf";
	cmd[1] = "-a";
	cmd[2] = "-l";
	cmd[3] = NULL;
	if (execve(path, cmd, environ) < 0)
		perror(NULL);
	printf("In case of failure, you will see this output\n");
}

/* 
	execve는 본 함수를 호출하는 프로세스를 path에 해당하는 파일을 실행하는 새 프로세스로 바꾼다.
	첫번째 인자는 실행할 파일의 경로이며, 두번째 인자는 옵션을 담는 문자열의 배열이다.
	(문자열도, 이중포인터도 null terminate 되어있어야한다).
	cmd[0]에 해당하는 문자열은 관습적으로 실행하는 프로그램의 이름을 쓰지만 위와 같이 해도 실행은 된다...
	위의 경우 “/bin/ls -a -l”이 실행되게 된다.

	세번째 인자는 환경변수이다.
	execve는 성공할 경우 아예 반환값이 없고 실패할 경우에만 -1을 반환한다.
	As the execve() function overlays the current process image with a new process image, 
	the successful call has no process to return to. 
	If execve() does return to the calling process, an error has occured;
*/
